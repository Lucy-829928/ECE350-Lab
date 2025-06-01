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

  unit32_t* MSP_INIT_VAL = *(uint32_t**)0x0;
  printf("MSP Init is : %p\r\n", MSP_INIT_VAL);

  uint32_t* sp = MSP_INIT_VAL - THREAD_STACK_SIZE;

  *(--sp) = 1 << 24;                             // xPSR (Thumb bit = 1)
  *(--sp) = (uint32_t)print_continuously;       // PC
  for (int i = 0 ; i < 14; i++)  *(--sp) = 0xA;

  switch_to_thread(sp);

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  printf("Hello, world!\r\n");
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

