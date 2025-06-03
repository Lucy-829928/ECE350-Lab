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
#include "main.h"
#include <stdio.h> //You are permitted to use this library, but currently only printf is implemented. Anything else is up to you!

/**
  * @brief  The application entry point.
  * @retval int
  */

// EX2: SVC_Handler - called when we invoke SVC instruction
void SVC_Handler(void);
// EX2: SVC_Handler_Main - get SVC number and deal with it
void SVC_Handler_Main(unsigned int* svc_args);

// EX3: print_continuously - function each thread will do
void print_continuously(void);
// EX3: osThreadStart - system calls SVC #1
void osThreadStart(uint32_t* stack);
// EX3: start_thread - restore registers and change back to PSP
void start_thread(uint32_t* new_stack);

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

  // >>>> EX1 & 3 start =================================================
  uint32_t* MSP_INIT_VAL = *(uint32_t**)0x0;	// dereference once to get the address in 0x0, which is the MSP_INIT_VAL
  printf("MSP Init is: %p\r\n", MSP_INIT_VAL);

  // assume stack size & thread#
	#define MAIN_STACK_SIZE     0x400
	#define THREAD_STACK_SIZE   0x400
	#define NUM_THREADS         3

  uint32_t* stack_addrs[NUM_THREADS];
  stack_addrs[0] = (uint32_t*)((uint8_t*)MSP_INIT_VAL - MAIN_STACK_SIZE); // (uint8_t*) to changed in Byte, since stack size is in Byte
  printf("Thread 1 stack start: %p\r\n", stack_addrs[0]);

  for (int i = 1; i < NUM_THREADS; ++i) {
      stack_addrs[i] = (uint32_t*)((uint8_t*)stack_addrs[i - 1] - THREAD_STACK_SIZE);
      printf("Thread %d stack start: %p\r\n", i + 1, stack_addrs[i]);
  }
  // <<<< EX1 & 3 end ===================================================


  // >>>> EX2 start =================================================
//	  __asm("SVC #0");
  // <<<< EX2 end ===================================================


  // >>>> EX3 start =================================================
  uint32_t* stackptr = stack_addrs[0]; // stack pointer that pointed to the stack base of thread 1
  *(--stackptr) = 1 << 24;                       // xPSR: Thumb bit
  *(--stackptr) = (uint32_t)print_continuously;  // PC: when SVC is exited, run print_continuously
  *(--stackptr) = 0xA;                    // LR
  *(--stackptr) = 0xA;                    // R12
  *(--stackptr) = 0xA;                    // R3
  *(--stackptr) = 0xA;                    // R2
  *(--stackptr) = 0xA;                    // R1
  *(--stackptr) = 0xA;                    // R0
  for (int i = 0; i < 8; i++) {
      *(--stackptr) = 0xA;               // R4–R11 (R11 first, then R10, ..., R4)
  }
  uint32_t* stack_top = stackptr; // stack pointer now pointed to the stack top of thread 1
  osThreadStart(stack_top);	// called the system to start thread with SVC #1
  // <<<< EX3 end ===================================================

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
//	  printf("Hello, world!\r\n");
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

__attribute__((naked)) void SVC_Handler(void)	// mark as naked function: not save registers and stack frames
{
	__asm volatile (
		"tst lr, #4			\n"	// LR holds EXC_RETURN when exception occurs; LR bit[2]: MSP/PSP original task is using; this line means (lr & 0x4) == 0, update Z flag: = 0 -> Z = 1, != 0 -> Z = 0
		"ite eq				\n" // "if-then-else" in Thumb: if Z = 1 -> EQ(==), else -> NE(!=)
		"mrseq r0, msp		\n" // EQ, LR bit[2] = 0, MSP; move(read) MSP(special register) to R0(common register)
		"mrsne r0, psp		\n" // NE, LR bit[2] = 1, MSP; move(read) PSP(special register) to R0(common register)
		"b SVC_Handler_Main \n" // branch to main logic function in C, it will auto pass R0 as parameter
	);
}

void SVC_Handler_Main(unsigned int* svc_args)
{
	uint32_t svc_num = 0;

	uint16_t* svc_pc = (uint16_t*)svc_args[6];  // PC's address at [6] of current SP
	uint16_t svc_instr = *(svc_pc - 1);  // 1.change to uint16_t* since data stored in the pointer(Instructions) is in 2 Bytes; 2."-1"(-1 two bytes = 1 instruction before) is where SVC instruction at
	svc_num = svc_instr & 0xFF;  // only extract lower 8 bits (0~7) = 2 Bytes

	printf(">>> SVC Number: %u\r\n", (unsigned int)svc_num);

	switch (svc_num) {
		case 0:
			printf("SVC 0: Hi~\r\n");
			break;
		case 1:
			printf("Syscall 1: start_thread\r\n");
			start_thread((uint32_t*)svc_args[0]);	// here svc_args[0] is the old data(stack_top of thread 1, which is R4) of R0, it auto stored in stack when osThreadStart(stack_top) called SVC
			break;
		default:
			printf("Unknown syscall: %u\r\n", (unsigned long)svc_num);
			break;
	}
}

__attribute__((noreturn)) void print_continuously(void)
{
	while(1)
	{
		printf("Thread!\r\n");
	}
}

void osThreadStart(uint32_t* stack)
{
    __asm volatile(
        "mov r0, %0    \n"	// move(store) %0(first parameter: stack_top of thread 1) to R0
        "svc #1        \n"	// call SVC #1
        :					// told the compiler no output
        : "r" (stack)		// told the compiler we put input "stack" into a common register
        : "r0"				// told the compiler register "R0" was edited
    );
}

__attribute__((naked)) void start_thread(uint32_t* new_stack)
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

