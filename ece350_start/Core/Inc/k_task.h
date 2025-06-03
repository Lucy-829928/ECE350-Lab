/*
 * k_task.h
 *
 *  Created on: Jan 5, 2024
 *      Author: nexususer
 *
 *      NOTE: any C functions you write must go into a corresponding c file that you create in the Core->Src folder
 */

#ifndef INC_K_TASK_H_
#define INC_K_TASK_H_

typedef unsigned int U32;
typedef unsigned short U16;
typedef char U8;
typedef unsigned int task_t;

typedef struct task_control_block {
	void (*ptask)(void* args); 	// entry address
	U32 stack_high; 			// starting address of stack (high address)
	task_t tid; 				// task ID
	U8 state; 					// task's state
	U16 stack_size; 			// stack size. Must be a multiple of 8
	// your own fields at the end
	U32 stack_low;				// ending address of stack (low address)
	U32* stack_ptr;				// pointed to the lowest address that contains data
} TCB;

void osKernelInit(void);
int osCreateTask(TCB* task);
int osKernelStart(void);
void osYield(void);
int osTaskInfo(task_t TID, TCB* task_copy);
task_t osGetTID(void);
int osTaskExit(void);

void start_thread(U32* new_stack);
void SVC_Handler_Main(task_t* svc_args);
void osSwitchTask(void);

#endif /* INC_K_TASK_H_ */
