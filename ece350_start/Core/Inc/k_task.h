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

// Type definitions
typedef unsigned int   U32;
typedef unsigned short U16;
typedef char           U8;
typedef unsigned int   task_t;

// Task Control Block structure
typedef struct task_control_block {
    void (*ptask)(void* args); // Entry address
    U32 stack_high;            // Starting address of stack (high address)
    task_t tid;                // Task ID
    U8 state;                  // Task's state
    U16 stack_size;            // Stack size. Must be a multiple of 8
    U32* sp;                   // Current stack pointer for this task
    // @z222ye: maybe it should be a signed int since what if deadline is negative?
    U32 deadline;               // Deadline for the task
} TCB;

// OS API
void osKernelInit();
int  osCreateTask(TCB* task);
void scheduler(void);
void osYield();
int  osTaskInfo(task_t TID, TCB* task_copy);
int  printTCB(task_t TID);
int  osTaskExit(void);
int  osKernelStart();
void osTaskExitHandler(void);
void create_idle_task();
task_t osGetTID();

// Externs
extern int g_current_task_idx;
extern TCB tcb_list[];
extern U32 g_main_return_lr;
extern U8 os_running;
extern U8 os_fallback_idle;

#endif /* INC_K_TASK_H_ */
