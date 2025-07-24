//#include "main.h"
//#include <stdio.h>
//#include "common.h"
//#include "k_task.h"
//#include "k_mem.h"
//
//#define  ARM_CM_DEMCR      (*(uint32_t *)0xE000EDFC)
//#define  ARM_CM_DWT_CTRL   (*(uint32_t *)0xE0001000)
//#define  ARM_CM_DWT_CYCCNT (*(uint32_t *)0xE0001004)
//
//
//
//
//int main(void)
//{
//
//  /* MCU Configuration: Don't change this or the whole chip won't work!*/
//
//  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
//  HAL_Init();
//  /* Configure the system clock */
//  SystemClock_Config();
//
//  /* Initialize all configured peripherals */
//  MX_GPIO_Init();
//  MX_USART2_UART_Init();
//  /* MCU Configuration is now complete. Start writing your code below this line */
//
//  osKernelInit();
//  k_mem_init();
//
//  if (ARM_CM_DWT_CTRL != 0) {        // See if DWT is available
//	  printf("Using DWT\r\n\r\n");
//      ARM_CM_DEMCR      |= 1 << 24;  // Set bit 24
//      ARM_CM_DWT_CYCCNT  = 0;
//      ARM_CM_DWT_CTRL   |= 1 << 0;   // Set bit 0
//  }else{
//	  printf("DWT not available \r\n\r\n");
//  }
//
//  int N = 100;
//  volatile U32* p_temp;
//  uint32_t timestamps[N+1];
//
////System under test---------------------
//  //measure time to allocate N block
//  for (int i = 0; i < N; i ++){
//	  timestamps[i] = ARM_CM_DWT_CYCCNT;
//	  p_temp = (U32*)k_mem_alloc(4);
//  }
//  timestamps[N] = ARM_CM_DWT_CYCCNT;
//  //print total clock ticks as well as ticks per iteration
//  printf("k_mem_alloc time: %lu\r\n", timestamps[N] - timestamps[0]);
//  printf("Time per iteration:\r\n");
//  for (int i = 0; i < N; i ++){
//	  printf("%u, ", timestamps[i+1] - timestamps[i]);
//  }
//  printf("\r\n\r\n");
//
///*
////Compiler's version-------------------
//  //measure time to allocate N block
//  for (int i = 0; i < N; i ++){
//	  timestamps[i] = ARM_CM_DWT_CYCCNT;
//	  p_temp = (U32*)malloc(4);
//  }
//  timestamps[N] = ARM_CM_DWT_CYCCNT;
//  //print total clock ticks as well as ticks per iteration
//  printf("malloc time: %lu\r\n", timestamps[N] - timestamps[0]);
//  printf("Time per iteration:\r\n");
//  for (int i = 0; i < N; i ++){
//	  printf("%u, ", timestamps[i+1] - timestamps[i]);
//  }
//  printf("\r\n\r\n");
//*/
//
//  printf("back to main\r\n");
//  while (1);
// }

#include "main.h"
#include <stdio.h>
#include "common.h"
#include "k_task.h"
#include "k_mem.h"
#include <stdint.h>

#define ARM_CM_DEMCR      (*(volatile uint32_t *)0xE000EDFC)
#define ARM_CM_DWT_CTRL   (*(volatile uint32_t *)0xE0001000)
#define ARM_CM_DWT_CYCCNT (*(volatile uint32_t *)0xE0001004)

// 系统时钟频率 (根据SystemClock_Config中的PLL配置计算得出)
#define SYSTEM_CLOCK_HZ   84000000    // 84MHz = (16MHz / 16 * 336) / 4

// 测试任务
void TaskSleep(void *p) {
    volatile uint32_t last_tick = 0;
    volatile uint32_t current_tick = 0;
    volatile uint32_t delta_us = 0;
    int test_phase = 1;

    // 初始化DWT计数器
    if (ARM_CM_DWT_CTRL != 0) {
        printf("---- test7 ----\r\n");
        printf("Using DWT for timing\r\n\r\n");
        ARM_CM_DEMCR |= 1 << 24;  // 使能DWT
        ARM_CM_DWT_CYCCNT = 0;    // 清零计数器
        ARM_CM_DWT_CTRL |= 1 << 0; // 启动计数器
    } else {
        printf("DWT not available\r\n");
        return;
    }

    printf("Task started\r\n");
    
    while(1) {
        last_tick = ARM_CM_DWT_CYCCNT;
        
        switch(test_phase) {
            case 1:
                printf("osSleep 5 ms\r\n");
                osSleep(5);
                break;
            case 2:
                printf("osSleep 1 ms\r\n");
                osSleep(1);
                break;
            case 3:
                printf("osSleep 1 ms\r\n");
                osSleep(1);
                break;
            case 4:
                printf("osSleep 1 ms\r\n");
                osSleep(1);
                break;
            default:
                osSleep(1000);  // 测试完成后长睡眠
                continue;
        }
        
        current_tick = ARM_CM_DWT_CYCCNT;
        delta_us = ((current_tick - last_tick) * 1000000) / SYSTEM_CLOCK_HZ;
        printf("Awake%d delta time =%lu us\r\n", test_phase, delta_us);
        
        test_phase++;
    }
}

int main(void)
{
    /* MCU Configuration: Don't change this or the whole chip won't work!*/
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();

    osKernelInit();
    k_mem_init();

    // 创建测试任务
    TCB task;
    task.stack_size = STACK_SIZE;

    // 创建任务，使用普通的osCreateTask，不需要特殊的deadline
    task.ptask = &TaskSleep;
    osCreateTask(&task);

    osKernelStart();

    while (1);
 }

