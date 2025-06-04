/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "common.h"
#include "k_task.h"
#include "main.h"
#include <stdio.h>
// You are permitted to use this library, but currently only printf is implemented. Anything else is up to you!

/**
  * @brief  The application entry point.
  * @retval int
  */

// EX3: print_continuously - function each thread will do
void print_continuously(void);
// EX3: osThreadStart - system calls SVC #1
void osThreadStart(U32* stack);
// EX3: start_thread - restore registers and change back to PSP
void start_thread(U32* new_stack);

int main(void)
{
  /* MCU Configuration: Don't change this or the whole chip won't work!*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* MCU Configuration is now complete. Start writing your code below this line */

  // // >>>> EX1 & 3 start =================================================
  // U32* MSP_INIT_VAL = *(U32**)0x0;	// dereference once to get the address in 0x0, which is the MSP_INIT_VAL
  // printf("MSP Init is: %p\r\n", MSP_INIT_VAL);

  // U32* stack_addrs[NUM_THREADS];
  // stack_addrs[0] = (U32*)((U8*)MSP_INIT_VAL - MAIN_STACK_SIZE); // (U8*) to changed in Byte, since stack size is in Byte
  // printf("Thread 1 stack start: %p\r\n", stack_addrs[0]);

  // for (int i = 1; i < NUM_THREADS; ++i) {
  //     stack_addrs[i] = (U32*)((U8*)stack_addrs[i - 1] - THREAD_STACK_SIZE);
  //     printf("Thread %d stack start: %p\r\n", i + 1, stack_addrs[i]);
  // }
  // // <<<< EX1 & 3 end ===================================================


  // >>>> EX2 start =================================================
  //	  __asm("SVC #0");
  // <<<< EX2 end ===================================================


  // >>>> EX3 start =================================================
  // U32* stackptr = stack_addrs[0]; // stack pointer that pointed to the stack base of thread 1
  // *(--stackptr) = 1 << 24;                       // xPSR: Thumb bit
  // *(--stackptr) = (U32)print_continuously;  // PC: when SVC is exited, run print_continuously
  // *(--stackptr) = 0xA;                    // LR
  // *(--stackptr) = 0xA;                    // R12
  // *(--stackptr) = 0xA;                    // R3
  // *(--stackptr) = 0xA;                    // R2
  // *(--stackptr) = 0xA;                    // R1
  // *(--stackptr) = 0xA;                    // R0
  // for (int i = 0; i < 8; i++) {
  //     *(--stackptr) = 0xA;               // R4–R11 (R11 first, then R10, ..., R4)
  // }
  // U32* stack_top = stackptr; // stack pointer now pointed to the stack top of thread 1
  // osThreadStart(stack_top);	// called the system to start thread with SVC #1
  // <<<< EX3 end ===================================================
  
  // Kernel init, start with null_task and verify their functionality
  osKernelInit(); // Initialize the kernel
  printf("Kernel initialized.\r\n");
  
  // Then verify functionality of osTaskInfo and osGetTID
  TCB task_info;
  task_t current_tid = osGetTID(); // Get the current task ID
  printf("Current TID: %d\r\n", current_tid);

  if (osTaskInfo(current_tid, &task_info) == RTX_OK) // Get task info
  {
    // Print actual task info, which should be the null task
    printf("Actual Task Info:\r\n");
    printf("TID: %d\r\n", task_info.tid);
    printf("State: %d\r\n", task_info.state);
    printf("Stack Size: %d\r\n", task_info.stack_size);
    printf("Stack High: %p\r\n", (void*)task_info.stack_high);
    printf("Stack Low: %p\r\n", (void*)task_info.stack_low);
    printf("Stack Pointer: %p\r\n", (void*)task_info.stack_ptr);
  }
  else
  {
    printf("Failed to get task info.\r\n");
  }

  if (osKernelStart() == RTX_ERR)
  {
    printf("Kernel failed to start.\r\n");
  }

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    // printf("Hello, world!\r\n");
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

__attribute__((noreturn)) void print_continuously(void)
{
	while(1)
	{
		printf("Thread!\r\n");
	}
}

void osThreadStart(U32* stack)
{
  __asm volatile(
      "mov r0, %0    \n"	// move(store) %0(first parameter: stack_top of thread 1) to R0
      "svc #1        \n"	// call SVC #1
      :					// told the compiler no output
      : "r" (stack)		// told the compiler we put input "stack" into a common register
      : "r0"				// told the compiler register "R0" was edited
  );
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

