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



#include "common.h"
#include "k_task.h"




void test_svc_call() {
    printf("\n\n\n\nAbout to call SVC #0 from user code.\n");
    __asm volatile ("SVC #17"); // Use volatile to prevent optimizer issues
    printf("Returned from SVC #0 call to user code.\n");
}


int test_a = 0;
int test_b = 0;

void test_task(void *) {
	for (int i = 0 ; i < 42; i++){
		printf("A %d \r\n", test_a ++);
		osYield();
	}
}


void test_task_b(void *) {
	for (int i = 0 ; i < 69; i++){
		printf("B %d \r\n", test_b ++);
		osYield();
	}
}

/**
  * @brief  The application entry point.
  * @retval int
  */
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
  printf(" \r\n ALL CODE EXECUTION BEGIN. \r\n");


  osKernelInit();

  TCB test_mytask;
  test_mytask.ptask = &test_task;
  test_mytask.stack_size = 0x400;

  osCreateTask(&test_mytask);

  TCB test_mytask_b;
  test_mytask_b.ptask = &test_task_b;
  test_mytask_b.stack_size = 0x400;

  osCreateTask(&test_mytask_b);

  osKernelStart();



  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  printf("ALL CODE EXECUTION COMPLETED. \r\n");
  while (1)
  {
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

