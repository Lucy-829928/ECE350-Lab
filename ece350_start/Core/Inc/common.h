/*
 * common.h
 *
 *  Created on: Jan 5, 2024
 *      Author: nexususer
 *
 *      NOTE: If you feel that there are common
 *      C functions corresponding to this
 *      header, then any C functions you write must go into a corresponding c file that you create in the Core->Src folder
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#define TID_NULL 0   // predefined Task ID for the NULL task
#define MAX_TASKS 16 // maximum number of tasks in the system
#define THREAD_STACK_SIZE 0x200 // min. size of each task’s stack
#define UNDEFINED -1 // state of task that is not defined
#define DORMANT 0 // state of terminated task
#define READY 1   // state of task that can be scheduled but is not running
#define RUNNING 2 // state of running task

#define RTX_OK    1
#define RTX_ERR   0

#define MAIN_STACK_SIZE  0x400	  // from pre-lab
#define MEMORY_FLOOR 0x20000000   // set a size for the minimal address of memory

#endif /* INC_COMMON_H_ */
