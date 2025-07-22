#include "k_task.h"
#include "common.h"
#include "stm32f4xx_it.h"
#include "core_cm4.h" // To access SysTick
#include <stdio.h> //You are permitted to use this library, but currently only printf is implemented. Anything else is up to you!

// TCB list global
TCB tcb_list[MAX_TASKS];

// stack addresses global
U8 os_running = 0;
U8 os_fallback_idle = 0; // Flag to indicate if we entered the fallback idle task
int g_current_task_idx; // <<< DEFINITION HERE
U32 g_main_return_lr;

U32 current_stack_top;
U32 zeroth_stack_top;

// ===================== OS API =====================

task_t osGetTID() {
    return (U8)g_current_task_idx;
}

void osKernelInit() {
    // printf("========== OS KERNEL INIT ========== \r\n");
    g_current_task_idx = -1;
    U32* MSP_INIT_VAL = *(U32**)0x0;
	current_stack_top = (U32)((U8*)MSP_INIT_VAL - MAIN_STACK_SIZE);
    zeroth_stack_top = current_stack_top;
    current_stack_top -= STACK_SIZE;

    // init all TCB blocks from TID = 0 to TID = max tasks -1 (all TCB blocks)
    for (int tcb_id = 0; tcb_id < MAX_TASKS; ++tcb_id) {
        tcb_list[tcb_id].tid = tcb_id;
        tcb_list[tcb_id].state = DORMANT;
        tcb_list[tcb_id].stack_high = INVALID_STACKPTR;
        tcb_list[tcb_id].stack_size = INVALID_STACKPTR;
        tcb_list[tcb_id].ptask = NULL;
        tcb_list[tcb_id].sp = INVALID_STACKPTR; // Initialize stack pointer to NULL
        tcb_list[tcb_id].deadline_remaining = 0xFFFFFFFF; // Initialize deadline to 0
    }
}

int osCreateTask(TCB* task) {
    if (task == NULL || task->ptask == NULL || task->stack_size % 8 != 0) {
        return RTX_ERR; // Invalid task parameters
    }
    // first find the next available spot
    int next_available_space = -1;
    for (int i = 1; i < MAX_TASKS; i++) {
        if (tcb_list[i].state == DORMANT) {
            next_available_space = i;
            break;
        }
    }
	// z222ye: switch the order of following 2 if statements
    if (next_available_space == -1) {
        return RTX_ERR;
    }
    if (task->stack_size == 0) {
        task->stack_size = STACK_SIZE;
    }
    task->deadline_remaining = 5; // Default deadline: 5ms
    // now we determine if the target has a stack high. If so, reuse it. If not so, do not reuse it.
    // prioritizes reuse (if a dormant exists we reuse the dormant instead of allocating a new one)
    if (tcb_list[next_available_space].stack_high == INVALID_STACKPTR) {
        // we get it a new one if this one doesn't work.
		// FIX @ z222ye: stack high and ptr is messing up with each other
        tcb_list[next_available_space].stack_high = current_stack_top;
        tcb_list[next_available_space].stack_size = task->stack_size;
        tcb_list[next_available_space].deadline_remaining = task->deadline_remaining;
    } else {
        // handle extreme situations
        if (task->stack_size > tcb_list[next_available_space].stack_size) {
            int refind_success = 0;
            // time to re-find the best replacement.
            for (int i = 1; i < MAX_TASKS; i++) {
                if (tcb_list[i].state == DORMANT && tcb_list[i].stack_size >= task->stack_size) {
                    next_available_space = i;
                    refind_success = 1;
                    tcb_list[next_available_space].deadline_remaining = task->deadline_remaining;
                    break;
                }
            }
            if (refind_success == 0) {
                return RTX_ERR;
            }
        }
    }
    // now we have the index ready.
    tcb_list[next_available_space].ptask = task->ptask;
    tcb_list[next_available_space].state = READY;
    U32* stackptr = (U32*)tcb_list[next_available_space].stack_high;
    *(--stackptr) = 0x01000000;
    *(--stackptr) = (U32)(tcb_list[next_available_space].ptask);  // PC: when SVC is exited, run print_continuously
    *(--stackptr) = (U32)osTaskExitHandler;                      // LR
    *(--stackptr) = next_available_space;                        // R12
    *(--stackptr) = next_available_space;                        // R3
    *(--stackptr) = next_available_space;                        // R2
    *(--stackptr) = next_available_space;                        // R1
    *(--stackptr) = next_available_space;                        // R0
    for (int i = 0; i < 8; i++) {
        *(--stackptr) = next_available_space;                    // R4–R11 (R11 first, then R10, ..., R4)
    }
    tcb_list[next_available_space].sp = stackptr; // Correct: sp now points to the prepared stack frame

    current_stack_top -= task->stack_size;

    task->sp = tcb_list[next_available_space].sp; // Set the stack pointer of the task
    task->state = tcb_list[next_available_space].state; // Set the state of the task
    task->tid = tcb_list[next_available_space].tid;
    task->stack_high = tcb_list[next_available_space].stack_high;

    if (os_running) {
        // If the OS is already running, we need to trigger a context switch
        // to ensure scheduler can pick this task if its deadline is earlier
        // @z222ye: one way to optimize is to only check whether new task has an earlier deadline
            // than current one, then we can choose to schedule to new task (imple new SVC opcode)
        __asm volatile("SVC #2"); // Trigger PendSV for context switch
    }
    return RTX_OK;
}

void idle_task() {
    // printf("IDLE task running. \r\n");
    while (1) {
        __asm volatile("WFI \n");
    }
    __asm volatile("SVC #3");
}

// run task 0 : IDLE task (task == run exit)
void create_idle_task() {
    tcb_list[0].ptask = &idle_task;
    tcb_list[0].state = READY;
    tcb_list[0].stack_high = zeroth_stack_top;
    tcb_list[0].stack_size = STACK_SIZE;
    tcb_list[0].deadline_remaining = 0xFFFFFFFF; // @z222ye: not sure if this is the best value
    U32* stackptr = (U32*)tcb_list[0].stack_high;
    *(--stackptr) = 0x01000000;
    *(--stackptr) = (U32)(tcb_list[0].ptask);  // PC: when SVC is exited, run print_continuously
    *(--stackptr) = (U32)osTaskExitHandler;    // LR
    *(--stackptr) = 0xF;                       // R12
    *(--stackptr) = 0xF;                       // R3
    *(--stackptr) = 0xF;                       // R2
    *(--stackptr) = 0xF;                       // R1
    *(--stackptr) = 0xF;                       // R0
    for (int i = 0; i < 8; i++) {
        *(--stackptr) = 0xF;                   // R4–R11 (R11 first, then R10, ..., R4)
    }
    tcb_list[0].sp = stackptr; // Correct: sp now points to the prepared stack frame
}

int osKernelStart() {
    // printf(" ============= KERNEL START ============= \r\n");
    if (os_running) {
        return RTX_ERR; // Kernel already started
    }
    create_idle_task();
    int first_task_idx = -1;
    U32 min_deadline = 0xFFFFFFFF;  // Initialize with maximum possible value
    
    // Find the first task in READY state
    // A more sophisticated scheduler might pick based on priority
    for (int i = 1; i < MAX_TASKS; ++i) {
        if (tcb_list[i].state == READY) {
            if (tcb_list[i].deadline_remaining < min_deadline) {
                min_deadline = tcb_list[i].deadline_remaining;
                first_task_idx = i;
            }
        }
    }
    // printf("\n starting kernel 0, got task idx %d \r\n", first_task_idx);
    if (first_task_idx == -1) {
        // No task to run, kernel cannot start.
        // This is an error, or could enter an idle loop. solution : set it to 0 to run idle task.
        first_task_idx = 0; // Or handle error appropriately
        os_fallback_idle = 1;
    }
    g_current_task_idx = first_task_idx;
    tcb_list[first_task_idx].state = RUNNING;
    // Trigger SVC to call launch_scheduler
    // The SVC_Handler (not implemented here) must be configured
    // to call launch_scheduler() when SVC number 16 is invoked.
    // printf("starting kernel 1 \r\n");
    os_running = 1; // Set the OS running flag
    // @z222ye: I am thinking shall we reset timer ticks here
        // Hope it works.
        // And hope it doesnt cause any other components to break.
    SysTick->VAL = 0;
    __asm volatile("SVC #1");
    // printf("\n YOUR PROGRAM IS DEAD \r\n");
    // Should not return from here if SVC is successful
    return RTX_ERR; // Indicate failure if SVC didn't switch context
}

void scheduler(void) {
    // @z222ye: sleep logic hasnt been implemented so we only imple basic EDF scheduler
    int prev_task_idx = g_current_task_idx;
    if (prev_task_idx != -1 && tcb_list[prev_task_idx].state == RUNNING) {
        tcb_list[prev_task_idx].state = READY; // Mark current task as ready (if it wasn't blocked/terminated)
    }

    // Find task with earliest deadline
    int earliest_deadline_task = -1;
    U32 min_deadline = 0xFFFFFFFF;

    // Search through all tasks except idle task (index 0)
    for (int i = 1; i < MAX_TASKS; i++) {
        if (tcb_list[i].state == READY) {
            if (tcb_list[i].deadline_remaining < min_deadline) {
                min_deadline = tcb_list[i].deadline_remaining;
                earliest_deadline_task = i;
            }
        }
    }
    
    // If we found a task with earliest deadline
    if (earliest_deadline_task != -1) {
        g_current_task_idx = earliest_deadline_task;
        tcb_list[g_current_task_idx].state = RUNNING;
        return;
    }
    
    // If no task is ready, fall back to idle task
    g_current_task_idx = 0;  // Idle task index
    tcb_list[g_current_task_idx].state = RUNNING;
    // @z222ye: maybe we can disable timer interrupt since here ... ?
    if (!os_fallback_idle) {
        os_fallback_idle = 1; // Set flag to indicate we entered the fallback idle task
        // printf("Entering fallback idle task. \r\n");
    } else {
        // we should never reach here so throw an error
        printf("Error: Already in fallback idle task and timed scheduler should not be called again.\r\n");
    }
}

void osYield() {
    __asm volatile("SVC #2");
}

int osTaskInfo(task_t TID, TCB* task_copy) {
    if (TID > (MAX_TASKS-1) || TID < 0 || task_copy == NULL || tcb_list[TID].state == DORMANT) {
        return RTX_ERR;
    }
    task_copy->ptask = tcb_list[TID].ptask;
    task_copy->sp = tcb_list[TID].sp;
    task_copy->stack_high = tcb_list[TID].stack_high;
    task_copy->stack_size = tcb_list[TID].stack_size;
    task_copy->state = tcb_list[TID].state;
    task_copy->tid = tcb_list[TID].tid;
    task_copy->deadline_remaining = tcb_list[TID].deadline_remaining; // Copy the deadline
    return RTX_OK;
}

int printTCB(task_t TID) {
    TCB test_tcb;
    osTaskInfo(TID, &test_tcb);
    printf("--- TCB [%d] --- \r\n", TID);
    printf("|== TCB program ptr 0x[%lx] ==| \r\n", test_tcb.ptask);
    printf("|== TCB stack ptr 0x[%lx] ==| \r\n", test_tcb.sp);
    printf("|== TCB stack high 0x[%lx] ==| \r\n", test_tcb.stack_high);
    printf("|== TCB state 0 dormant 1 ready 2 running: [%d] ==| \r\n", test_tcb.state);
    printf("|== TCB stack size [%d] ==| \r\n", test_tcb.stack_size);
    printf("|== TCB deadline_remaining [%d] ==| \r\n", test_tcb.deadline_remaining);
    printf("--- TCB printout completed ---\r\n");
    return 0;
}

int osTaskExit(void) {
    osTaskExitHandler();
}

void osTaskExitHandler(void) {
    // printf("Task %lu exited by returning.\r\n", g_current_task_idx);
    tcb_list[g_current_task_idx].state = DORMANT; // Mark task as dormant
    // Trigger PendSV to switch to another task
    // This is a critical part of a real scheduler
    // For now, this will effectively halt if no proper scheduler exists
    // Or, if we have a PendSV handler, it will pick the next task.
    // after redistribution, if there is no additional tasks, return.
    int task_count = 0;
    for (int i = 0 ; i < MAX_TASKS; i++) {
        if (tcb_list[i].state != DORMANT) {
            break;
        }
        task_count++;
    }
    // if run out of tasks, return. Else, we want it to reschedule.
    if (task_count == MAX_TASKS) {
		// z222ye: but this case is not expected to happen, as we always have an idle task
        // printf("Final state of global LR entry point: %d \r\n", g_main_return_lr);
        return;
    } else {
        __asm volatile("SVC #2"); // SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
    }
    while(1); // Should not return from here after PendSV
}


