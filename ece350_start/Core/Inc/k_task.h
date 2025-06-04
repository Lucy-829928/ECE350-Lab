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

#define TCB_STRUCT_SIZE 20

typedef unsigned int U32;
typedef unsigned short U16;
typedef char U8;
typedef unsigned int task_t;
typedef struct task_control_block {
	void (*ptask)(void* args); //entry address
	U32 stack_high; //starting address of stack (high address)
	task_t tid; //task ID
	U8 state; //task's state
	U16 stack_size; //stack size. Must be a multiple of 8
	//your own fields at the end
    U32* sp;                   // Current stack pointer for this task

} TCB;


int osKernelInit();
int osCreateTask(TCB* task);
void scheduler(void);
void osYield();
int osTaskInfo(task_t TID, TCB* task_copy);
int printTCB(task_t TID);
int osTaskExit(void);
int osKernelStart();
void osTaskExitHandler(void);

void init_tcb(TCB* tcb, task_t tid, void (*task_func)(void*), U16 stack_size_bytes, U8 initial_state, void* task_args);
extern int g_current_task_idx;
extern TCB tcb_list[];

#endif /* INC_K_TASK_H_ */
