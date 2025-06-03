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

void osKernelInit(void)
{
	// initialize entries of TCB array
	for (int i = 0; i < MAX_TASKS; i++)
    {
        tcb_arr[i].tid = i;
        tcb_arr[i].state = DORMANT;
        tcb_arr[i].stack_size = STACK_SIZE;
        tcb_arr[i].ptask = 0;
        tcb_arr[i].stack_high = 0;
        tcb_arr[i].stack_low = 0;
        tcb_arr[i].stack_ptr = NULL;
    }
    current_tid = -1; // initialize current_tid as -1, invalid
    task_count = 0;   // initialize task_count = 0;
    kernel_init = 1;

    // initialize stack address that is available for thread stack
    U32* MSP_INIT_VAL = *(U32**)0x0;
    task_ptr = MSP_INIT_VAL - MAIN_STACK_SIZE;
}

int osCreateTask(TCB* task)
{
	if(task_count >= MAX_TASKS || task->stack_size %8 != 0 || task->stack_size <= STACK_SIZE || task == NULL || task->ptask == NULL)
	{
		return RTX_ERR; // 0
	}

	// check if memory space is large enough for a new stack
	if ((U32*)((U8*)task_ptr - task->stack_size) < MEMORY_FLOOR)
	{
	    return RTX_ERR;  // 0
	}

	int id = task_count;
	task->tid = id;
	task->state = READY;

	TCB* t = &tcb_arr[id];

	// mark stack high and set space for task stack
    task->stack_high = task_ptr;
    task->stack_low = (U32*)((U8*)task_ptr - task->stack_size);

    *(--task_ptr) = 1 << 24;                // xPSR: Thumb bit
	*(--task_ptr) = (U32)(task->ptask);  		// PC: when SVC is exited, run print_continuously
	*(--task_ptr) = 0xA;                    // LR
	*(--task_ptr) = 0xA;                    // R12
	*(--task_ptr) = 0xA;                    // R3
	*(--task_ptr) = 0xA;                    // R2
	*(--task_ptr) = 0xA;                    // R1
	*(--task_ptr) = 0xA;                    // R0
	for (int i = 0; i < 8; i++) {
		*(--task_ptr) = 0xA;               // R4–R11 (R11 first, then R10, ..., R4)
	}
	task->stack_ptr = task_ptr;
	task_ptr = task->stack_low;

	t->tid = id;
	t->state = READY;
	t->stack_size = task->stack_size;
	t->ptask = task->ptask;
	t->stack_high = task->stack_high;
	t->stack_low  = task->stack_low;
	t->stack_ptr  = task->stack_ptr;

	task_count++;
	return RTX_OK; // 1
}

int osKernelStart(void)
{
	if(kernel_inti == 0 || task_count == 0 || kerne_running == 1)
	{
		return RTX_ERR; // 0
	}

	for (int i = 0; i < MAX_TASKS; i++)
	{
		if (tcb_arr[i].state == READY)  // finding the first ready state
		{
			current_tid = i;
			tcb_arr[i].state = RUNNING;

			// running the kernel
			kernel_running = 1;
			start_thread(tcb_arr[i].stack_low);
			// never returned if found
		}
	}
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

}

task_t osGetTID(void)
{

}

int osTaskExit(void)
{

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

}
