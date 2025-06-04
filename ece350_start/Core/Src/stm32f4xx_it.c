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
	        "POP {PC}\n"                 // Return from exception.
	        ".align\n"                   // Ensure proper alignment



	);

}

__attribute__((naked)) void init_first_task(void){
    // printf("got task ID = %d \r\n", g_current_task_idx); // Keep this for debugging
    __asm volatile (
        ".syntax unified\n"
        ".thumb\n"
        "LDR R0, =g_current_task_idx\n"  // R0 = address of g_current_task_idx
        "LDR R0, [R0]\n"                 // R0 = value of g_current_task_idx (the index, e.g., 0, 1, ...)

        "LDR R1, =tcb_list\n"            // R1 = base address of tcb_list array
        "MOV R2, %[TCB_SIZE_IMM]\n"      // R2 = size of one TCB structure (e.g., 20)
                                         // Alternative if TCB_SIZE_IMM is > 255: LDR R2, =TCB_STRUCT_SIZE then LDR R2, [R2]
        "MUL R0, R0, R2\n"               // R0 = index * TCB_STRUCT_SIZE (byte offset into array)
        "ADD R1, R1, R0\n"               // R1 = &tcb_list[g_current_task_idx] (address of the current TCB)

        // Now R1 holds the address of the TCB struct for the current task
        "LDR R0, [R1, %[OFFSET_SP_IMM]]\n" // R0 = current_tcb->sp (task's stack pointer)
        "MSR PSP, R0\n"                  // Set PSP to task's stack pointer

        "MOV R0, #0x02\n"                // Use PSP for thread mode (SPSEL=1)
        "MSR CONTROL, R0\n"
        "ISB\n"                          // Instruction Synchronization Barrier

        "MRS R2, PSP\n"                  // R2 = task's SP (should point to where R4 is saved)
        "LDMIA R2!, {R4-R11}\n"          // Load R4-R11 from task stack, R2 updated
        "MSR PSP, R2\n"                  // Update PSP to new top (after R4-R11 loaded)

        "MOV LR, #0xFFFFFFFD\n"          // EXC_RETURN: To Thread mode, using PSP.
        "BX LR\n"                        // This will pop R0-R3, R12, LR, PC, xPSR from PSP

        : // No output operands
        : [OFFSET_SP_IMM] "I" (offsetof(TCB, sp)), // Must be an immediate
          [TCB_SIZE_IMM] "I" (TCB_STRUCT_SIZE)     // Must be an immediate
        : "r0", "r1", "r2", "memory"     // r2 is clobbered
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
    printf("--- SVC_Handler_main entered ---\r\n"); // Added newline for clarity

    switch (svc_opcode) {
        case 0:
            printf("SVC_Handler_main: SVC #0 called and processed.\r\n");
            // Example: Toggle an LED or set a flag
            // HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin); // If you have an LED (e.g. on Nucleo PA5)
            break;
        case 1:

        	// OS Scheduler launch. Load 1st item
        	printf("Launching first task \r\n");
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

        case 16:

        	// pendSV call
        	printf("SVC_Handler_main: SVC 16 called, doing context switch. \r\n");

        	break;

        case 17:
            printf("SVC_Handler_main: SVC #17 called.\r\n");
            break;
        // Add more cases as needed
        default:
            printf("SVC_Handler_main: Unknown SVC #%d called.\r\n", svc_opcode);
            break;
    }

    printf("--- SVC_Handler_main exiting ---\r\n");
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
  * @brief This function handles Pendable request for system service.
  */


/*
__attribute__((naked)) void PendSV_Handler(void)
{
     __asm volatile (
        ".syntax unified\n"
        ".thumb\n"

        // 1. Disable interrupts (optional but good practice during critical context switch)
        // "CPSID I\n" // Disable interrupts globally

        // 2. Save the rest of the current task's context (R4-R11)
        //    The processor already saved R0-R3, R12, LR, PC, xPSR on PSP.
        "MRS R0, PSP\n"             // R0 = current task's PSP

                                    // If current task is the first task ever run and no context saved yet,
                                    // PSP might not be valid yet for storing.
                                    // This assumes osKernelStart has run at least one task.
                                    // Or, if g_current_task_idx is -1 (or some invalid marker), skip save.
                                    // For simplicity now, we assume a valid task was running.

        "STMDB R0!, {R4-R11}\n"     // Save R4-R11 onto the task's stack. R0 is updated to new stack top.
                                    // R0 now points to the location where R4 was stored.

        // 3. Save the current task's updated PSP value into its TCB
        //    current_tcb->sp = R0;
        "LDR R1, =g_current_task_idx\n" // R1 = address of g_current_task_idx
        "LDR R2, [R1]\n"                // R2 = value of g_current_task_idx (current task's index)

        // Optional: Check if R2 is a valid index (e.g. not -1 if no task was running)
        // For now, assume it's valid.
        // "CMP R2, #0\n"
        // "BLT skip_save_sp\n" // If index is negative, for example

        "LDR R3, =tcb_list\n"           // R3 = base address of tcb_list
        "MOV R4, %[TCB_SIZE_IMM]\n"     // R4 = sizeof(TCB)
        "MLA R2, R2, R4, R3\n"          // R2 = &tcb_list[current_index] = (current_index * sizeof(TCB)) + tcb_list_base

        "STR R0, [R2, %[OFFSET_SP_IMM]]\n" // current_tcb->sp = R0 (the saved PSP)
    // "skip_save_sp:\n"


        // 4. Call the C scheduler function to choose the next task
        //    This will update g_current_task_idx.
        //    The Link Register (LR) will be corrupted by BL, but that's fine here
        //    as we are in Handler mode and will return using BX LR with an EXC_RETURN value.
        //    However, the original EXC_RETURN value IS in LR when PendSV is entered.
        //    If scheduler is complex and might also want to trigger exceptions or modify mode,
        //    it's safer to PUSH {LR} (EXC_RETURN) onto MSP and POP it before the final BX LR.
        "PUSH {LR}\n"                   // Save EXC_RETURN (currently in LR) onto MSP
        "BL scheduler\n"
        "POP {LR}\n"                    // Restore EXC_RETURN into LR (important for the final BX LR)
            "ISB\n"                          // Instruction Synchronization Barrier

        // 5. Load the new task's PSP from its TCB
        //    R0 = new_tcb->sp;
        "LDR R1, =g_current_task_idx\n" // R1 = address of g_current_task_idx (now potentially updated)
        "LDR R2, [R1]\n"                // R2 = value of g_current_task_idx (new task's index)

        "LDR R3, =tcb_list\n"           // R3 = base address of tcb_list
        // R4 still contains TCB_STRUCT_SIZE
        "MLA R2, R2, R4, R3\n"          // R2 = &tcb_list[new_index] = (new_index * sizeof(TCB)) + tcb_list_base

        "LDR R0, [R2, %[OFFSET_SP_IMM]]\n" // R0 = new_tcb->sp (this SP points to where R4 is stored for the new task)


        // 6. Restore the new task's context (R4-R11) from its stack
        "LDMIA R0!, {R4-R11}\n"     // Load R4-R11 from the new task's stack. R0 is updated.

        // 7. Update PSP to the new task's stack pointer
        "MSR PSP, R0\n"

        // 8. Enable interrupts (if disabled earlier)
        // "CPSIE I\n"

        // 9. Exit exception:
        //    LR should contain the EXC_RETURN value (e.g., 0xFFFFFFFD for returning to Thread mode using PSP).
        //    This was either preserved from entry or restored via POP {LR}.
        //    The processor will automatically unstack R0-R3, R12, (original)LR, PC, xPSR from the new PSP.
        "BX LR\n"

        : // No output operands
        : [OFFSET_SP_IMM] "I" (offsetof(TCB, sp)), // Must be an immediate
          [TCB_SIZE_IMM] "I" (TCB_STRUCT_SIZE)     // Immediate for TCB size
        : "r0", "r1", "r2", "r3", "r4", "memory" // Clobbered registers
    );

     printf("PENDSV FINISHED \r\n");
}
*/



/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

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
