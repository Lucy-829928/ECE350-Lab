/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
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
#include "common.h"
#include "stm32f4xx_it.h"
#include "k_task.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void) {
    printf("!!! HardFault !!!\r\n");
    printf("HFSR: 0x%08lX\r\n", SCB->HFSR);
    printf("CFSR: 0x%08lX\r\n", SCB->CFSR);
    if (SCB->CFSR & SCB_CFSR_MMARVALID_Msk) {
        printf("MMFAR: 0x%08lX\r\n", SCB->MMFAR);
    }
    if (SCB->CFSR & SCB_CFSR_BFARVALID_Msk) {
        printf("BFAR: 0x%08lX\r\n", SCB->BFAR);
    }

    // You can also try to get stacked registers if you know which stack (MSP/PSP) was active
    // This is more complex to do robustly here. A debugger is better.

    while (1) {}
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
__attribute__((naked)) void SVC_Handler(void)
{
//  /* USER CODE BEGIN SVCall_IRQn 0 */
//
//  /* USER CODE END SVCall_IRQn 0 */
//  /* USER CODE BEGIN SVCall_IRQn 1 */
//
//  /* USER CODE END SVCall_IRQn 1 */
	__asm volatile (
          // 1. Disable interrupts
          // @z222ye: I choose to disable timer interrupt
              // but maybe there is a better way to handle this
          "CPSID I\n"
	        ".syntax unified\n"          // Ensure unified syntax
	        ".thumb\n"                   // Ensure Thumb mode
	        "TST LR, #4\n"               // Test bit 2 of LR (EXC_RETURN value).

          "ITE EQ\n"                   // If-Then-Else
          "MRSEQ R0, MSP\n"            // If bit 2 is 0 (MSP), R0 = MSP
          "MRSNE R0, PSP\n"            // If bit 2 is 1 (PSP), R0 = PSP
	        "LDR R1, [R0, #24]\n"        // R1 = stacked PC (address of instruction AFTER SVC)
	        "LDRB R0, [R1, #-2]\n"       // R0 = byte at (stacked PC - 2), which is the imm8 value.
	                                     // R0 is now the first argument for SVC_Handler_main

	        "PUSH {LR}\n"                // Save LR (EXC_RETURN value) to stack.
	                                     // We need to preserve it because BL will overwrite LR.

	        "BL SVC_Handler_main\n"      // Call the C function. R0 has the opcode.

          // 8. Enable interrupts
          // @z222ye: I choose to disable timer interrupt
              // but maybe there is a better way to handle this
          "CPSIE I"
	        "POP {PC}\n"                 // Return from exception.
	        ".align\n"                   // Ensure proper alignment
	);
}

__attribute__((naked)) void init_first_task(void){
    __asm volatile (
        ".syntax unified\n"
        ".thumb\n"

        "CPSID I\n"                          // Disable interrupts

        // Part 1: Save R4-R11 of the current context (main) into Task 0's pre-allocated R4-R11 slot
        "LDR R0, =tcb_list\n"                // R0 = &tcb_list[0] (TCB array base)
        "LDR R1, [R0, %[OFFSET_SP_IMM]]\n"   // R1 = tcb_list[0].sp. This was set by os_task_stack_init
                                             // and points to where Task 0's R4 is on its stack.
        // R4-R11 currently hold main's context. Store them directly into Task 0's stack.
        "STMIA R1, {R4-R11}\n"               // Store current R4-R11 (main's) to the location pointed to by R1
                                             // (Task 0's R4 slot) and subsequent words for R5-R11.
                                             // R1 is not updated (no "!" mark). tcb_list[0].sp remains correct.

        // Save main's LR (return address to caller of this function in main)
        "LDR R2, =g_main_return_lr\n"
        "STR LR, [R2]\n"

        // Part 2: Switch to the first *real* task (g_current_task_idx should be > 0)
        "LDR R0, =g_current_task_idx\n"
        "LDR R0, [R0]\n"                     // R0 = value of g_current_task_idx (e.g., 1)

        "LDR R1, =tcb_list\n"                // R1 = base address of tcb_list array
        "MOV R2, %[TCB_SIZE_IMM]\n"          // R2 = size of one TCB structure
        "MUL R0, R0, R2\n"                   // R0 = index * TCB_STRUCT_SIZE (byte offset)
        "ADD R1, R1, R0\n"                   // R1 = &tcb_list[g_current_task_idx] (address of the current task's TCB)

        "LDR R0, [R1, %[OFFSET_SP_IMM]]\n"   // R0 = current_tcb->sp (task's stack pointer, points to its R4)
        "MSR PSP, R0\n"                      // Set PSP to task's stack pointer (points to R4)

        "MOV R0, #0x02\n"                    // Use PSP for thread mode (SPSEL=1 in CONTROL register)
        "MSR CONTROL, R0\n"
        "ISB\n"                              // Instruction Synchronization Barrier

        // Restore R4-R11 for the new task from its stack
        "MRS R2, PSP\n"                      // R2 = task's SP (should point to where R4 is saved)
        "LDMIA R2!, {R4-R11}\n"              // Load R4-R11 from task stack, R2 updated
        "MSR PSP, R2\n"                      // Update PSP to new top (after R4-R11 loaded)
        "CPSIE I\n"                          // Re-enable interrupts

        "MOV LR, #0xFFFFFFFD\n"              // EXC_RETURN: Return to Thread mode, using PSP.
        "BX LR\n"                            // This will pop R0-R3, R12, LR, PC, xPSR from new task's PSP

        : // No output operands
        : [OFFSET_SP_IMM] "I" (offsetof(TCB, sp)),
          [TCB_SIZE_IMM]  "I" (TCB_STRUCT_SIZE)
        : "r0", "r1", "r2", "memory", "cc" // Clobbered registers
    );
}

__attribute__((naked)) void return_to_main(){
	__asm volatile(
        ".syntax unified\n"
        ".thumb\n"
		    "CPSID I \n"                          // Disable interrupts briefly

		    // 1. Switch CPU from PSP to MSP.
		    //    MSP currently points to where main's stack was when os_start_first_task_and_capture_main was called.
		    "MRS R0, CONTROL \n"
		    "BIC R0, R0, #0x02 \n"                // Clear bit 1 (SPSEL) to select MSP
		    "MSR CONTROL, R0 \n"
		    "ISB \n"                              // Ensure CONTROL change takes effect

		    // 2. Load the saved LR (return address into main)
		    "LDR R1, =g_main_return_lr \n"
		    "LDR LR, [R1] \n"                     // LR = original return address in main

		    "CPSIE I \n"                          // Re-enable interrupts

		    // 3. Return to main.
		    //    R4-R11 are already restored to main's values.
		    //    MSP is now active and at the correct position.
		    //    LR now points to the instruction in main after the call to os_start_first_task_and_capture_main.
		    "BX LR \n"                            // Branch back to main
	        : // No output operands
	        : // No input symbolic constants needed here beyond global addresses
	        : "r0", "r1", "lr", "memory", "cc" // r0, r1, lr are clobbered
	);
}

// SVC opcodes:
// SVC 0 == BEGIN (iterate to next available slot)
// SVC 1 == scheduler
// SVC 2 == context switch
// SVC default = RETURN
// SVC 65536 == TEST

void SVC_Handler_main(int svc_opcode){
    // If you want to ensure printf flushes, you might need to explicitly call fflush(stdout)
    // or ensure your _write function handles this appropriately (ITM_SendChar usually flushes per char)
    //printf("--- SVC_Handler_main entered ---\r\n"); // Added newline for clarity

    switch (svc_opcode) {
        case 0:
            //printf("SVC_Handler_main: SVC #0 called and processed.\r\n");
            // Example: Toggle an LED or set a flag
            // HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin); // If you have an LED (e.g. on Nucleo PA5)
            break;
        case 1:
            // OS Scheduler launch. Load 1st item
            //printf("Launching first task \r\n");
            init_first_task();
            break;
        case 2:
            // Set PendSV bit to request a context switch
            SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
            // Barrier to ensure the write completes before returning,
            // especially if interrupts are about to be re-enabled.
            __DSB();
            __ISB();
            break;
        case 3:
            // go back to main.
            //printf("Returning to main. return condition met, only idle task remain. \r\n");
            return_to_main();
            break;
        default:
            //printf("SVC_Handler_main: Unknown SVC #%d called.\r\n", svc_opcode);
            break;
    }
    //printf("--- SVC_Handler_main exiting ---\r\n");
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */
  if (os_running) {
    for (int i = 1; i < MAX_TASKS; i++) {
        if (tcb_list[i].state == SLEEPING) {
            if (tcb_list[i].deadline > 0) {
                tcb_list[i].deadline--; // Decrement deadline
            }
            if (tcb_list[i].deadline <= 0) {
                tcb_list[i].state = READY; // Wake up the task
            }
        }
        if (tcb_list[i].state == RUNNING || tcb_list[i].state == READY) {
            // If the task is running, we might want to update its deadline or other state
            tcb_list[i].deadline--; // Decrement deadline for running task
            if (tcb_list[i].deadline <= 0) {
                // this is not allowed in EDF algorithm so we throw an error
                printf("Error: Task %d has reached its deadline while running!\r\n", tcb_list[i].tid);
                // @z222ye: may be we can handler this case in a better way
            }
        }
        SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
        __DSB(); // Ensure the PendSV is set before returning
        __ISB(); // Ensure the instruction is complete before returning
    }
  }
  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
