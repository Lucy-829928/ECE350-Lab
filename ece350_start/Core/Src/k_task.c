#include "k_task.h"
#include "common.h"
#include <stdio.h>

TCB tcb_arr[MAX_TASKS];	  // create an array to store TCB
int current_tid = -1;     // set initial current_tid as -1, invalid
int task_count = 0;       // set initial task_count = 0;
U32* task_ptr = 0;		  // point to the different stack address when we set stack

// for osKernelStart
int kernel_init = 0;
int kernel_running = 0;

// TODO: stack_high, low, ptr, ptask, some are U32, some are U32*,
// but when casting, we seems confuse them, will cause error? 
// After assuming current task is valid, insert the task into the TCB array
void OsInsertTask(TCB* task, U32* stack_base, int is_null_task) {
	int id;
	if (is_null_task) id = TID_NULL; // if inserting null task, set id to TID_NULL
	else id = task_count;

    task->tid = id;
    task->state = READY;

    task->stack_high = (U32)stack_base;
    task->stack_low = (U32)((U8*)stack_base - task->stack_size);

    U32* sp = stack_base;
    *(--sp) = 1 << 24;                // xPSR: Thumb bit
    *(--sp) = (U32)(task->ptask);     // PC
    *(--sp) = 0xA;                    // LR
    *(--sp) = 0xA;                    // R12
    *(--sp) = 0xA;                    // R3
    *(--sp) = 0xA;                    // R2
    *(--sp) = 0xA;                    // R1
    *(--sp) = 0xA;                    // R0
    for (int i = 0; i < 8; i++) {
        *(--sp) = 0xA;                // R4–R11
    }

    task->stack_ptr = sp;

    TCB* t = &tcb_arr[id];
    t->tid = task->tid;
    t->state = task->state;
    t->stack_size = task->stack_size;
    t->ptask = task->ptask;
    t->stack_high = task->stack_high;
    t->stack_low  = task->stack_low;
    t->stack_ptr  = task->stack_ptr;

    task_count++;

    stack_base = (U32*)task->stack_low;
}

void OsInsertNullTask(U32* stack_base)
{
	TCB null_task = (TCB){ 
		.ptask = (U32)idle,
		.stack_size = THREAD_STACK_SIZE,
		.tid = 0xff,
		.stack_high = 0
	};

	OsInsertTask(&null_task, stack_base, 1); // insert null task with is_null_task = 1
}

void osKernelInit(void)
{
	// initialize entries of TCB array
	for (int i = 0; i < MAX_TASKS; i++)
    {
        tcb_arr[i].tid = i;
        tcb_arr[i].state = UNDEFINED;
        tcb_arr[i].stack_size = THREAD_STACK_SIZE;
        tcb_arr[i].ptask = NULL;
        tcb_arr[i].stack_high = 0;
        tcb_arr[i].stack_low = 0;
        tcb_arr[i].stack_ptr = NULL;
    }
    current_tid = -1; // initialize current_tid as -1, invalid
    task_count = 0;   // initialize task_count = 0;
    kernel_init = 1;

	// initialize stack address that is available for thread stack
	U32* MSP_INIT_VAL = *(U32**)0x0;
	task_ptr = MSP_INIT_VAL - (MAIN_STACK_SIZE / sizeof(U32));

	// insert the NULL task
	OsInsertNullTask(task_ptr);
}

static void idle(void *arg)
{
    for (;;)
    {
        __asm volatile ("WFI");
    }
}

int osCreateTask(TCB* task)
{
    if (task_count >= MAX_TASKS || 
        task->stack_size %8 != 0 || 
        task->stack_size < THREAD_STACK_SIZE || 
        task == NULL || 
        task->ptask == NULL)
		// TODO: stack size can be 0 then we can use the default size
		// TODO: how about other attributes? pid?
    {
        return RTX_ERR; // 0
    }

    // TODO: why comes memory floor? I didnt see perhaps missed
    	// should comes from (U32*)((U8*)MSP_INIT_VAL - _Min_Stack_Size)
	U32* MSP_INIT_VAL = *(U32**)0x0;
    if ((U32*)((U8*)task_ptr - task->stack_size) < (U32*)((U8*)MSP_INIT_VAL - MAX_STACK_SIZE)) {
        return RTX_ERR;  // 0
    }

    OsInsertTask(task, task_ptr, 0);
    return RTX_OK; // 1
}

int osKernelStart(void)
{
	if (kernel_init == 0 || task_count == 0 || kernel_running == 1)
	{
		return RTX_ERR; // 0
	}

	for (int i = TID_NULL + 1; i < MAX_TASKS; i++)
	{
		if (tcb_arr[i].state == READY)  // finding the first ready state
		{
			current_tid = i;
			tcb_arr[i].state = RUNNING;

			// running the kernel
			kernel_running = 1;
			// TODO: which one should we pass, stack_low or stack_ptr?
			start_thread(tcb_arr[i].stack_low);
			// never returned if found
		}
	}
	// If no task found, run the idle task
	current_tid = TID_NULL; // set current_tid to NULL task
	tcb_arr[TID_NULL].state = RUNNING;
	start_thread(tcb_arr[TID_NULL].stack_low);

	// We should never reach here, but if we do, return error
	return RTX_ERR; // 0
}

void osYield(void)
{
	__asm volatile(
		"svc #1 \n"
	);
}

int osTaskInfo(task_t TID, TCB* task_copy)
{
	if (TID < TID_NULL || TID >= MAX_TASKS || task_copy == NULL) {
		return RTX_ERR; // 0
	}

	if (tcb_arr[TID].state == UNDEFINED) {
		return RTX_ERR; // 0
	}

	// Copy the task information from the TCB array to the provided task_copy
	TCB* task = &tcb_arr[TID];
	task_copy->tid = task->tid;
	task_copy->state = task->state;
	task_copy->stack_size = task->stack_size;
	task_copy->ptask = task->ptask;
	task_copy->stack_high = task->stack_high;
	task_copy->stack_low = task->stack_low;
	task_copy->stack_ptr = task->stack_ptr;

	return RTX_OK; // 1
}

task_t osGetTID(void)
{
	if (current_tid < TID_NULL || current_tid >= MAX_TASKS) {
		// We should never reach here, but if we do, return error
		printf("Error: Invalid current_tid %d\r\n", current_tid);
		return TID_NULL; // return NULL task ID if current_tid is invalid
	}
	return tcb_arr[current_tid].tid; // return the current task's TID
}

int osTaskExit(void)
{
	// TODO: Implement task exit logic
}

__attribute__((naked)) void start_thread(U32* new_stack)
{
	__asm volatile(
        "ldmia r0!, {r4-r11}  \n"  // "LDMIA": load multiple, increment after; restore R4~R11, R0 then pointed to next PSP
		"msr psp, r0          \n"  // move(read) the data(incremented address) in R0(common register) to PSP(special register)

        "movs r1, #2          \n"  // move(read) the data 0 to R1
        "msr CONTROL, r1      \n"  // CONTROL = 0b10 -> thread mode, privileged, use PSP
        "isb                  \n"  // ISB: instruction synchronization barrier, to make sure the above settings of PSP/CONTROL is active

		"ldr lr, =0xFFFFFFFD  \n"  // manually set LR to EXC_RETURN, 0xFFFFFFFD = back to thread mode with PSP
        "bx lr                \n"  // back to the next line where interrupt started(since we set PC in stack, so it will run print_continuously), special registers will be auto popped out
    );
}

void SVC_Handler_Main(task_t* svc_args)
{
	U32 svc_num = 0;

	U16* svc_pc = (U16*)svc_args[6];  // PC's address at [6] of current SP
	U16 svc_instr = *(svc_pc - 1);  // 1.change to uint16_t* since data stored in the pointer(Instructions) is in 2 Bytes; 2."-1"(-1 two bytes = 1 instruction before) is where SVC instruction at
	svc_num = svc_instr & 0xFF;  // only extract lower 8 bits (0~7) = 2 Bytes

	printf(">>> SVC Number: %u\r\n", (task_t)svc_num);

	switch (svc_num) {
		case 0:
			printf("SVC 0: Hi~\r\n");
			break;
		case 1:
			printf("Syscall 1: \r\n");
			osSwitchTask();
			break;
		default:
			printf("Unknown syscall: %u\r\n", (task_t)svc_num);
			break;
	}
}

void osSwitchTask(void)
{
	// TODO: Implement task switching logic
}
