// pendsv_handler.s
.syntax unified
.thumb
.global PendSV_Handler  // Make the symbol visible to the linker
.type PendSV_Handler, %function // Specify it's a function

// same as macros from k_task.h
.equ TCB_STRUCT_SIZE, 32    // Size of TCB struct (9 fields × 4 bytes each)
.equ SP_OFFSET, 16         // Offset of sp field in TCB struct

PendSV_Handler:
    // 1. Disable interrupts
    // @z222ye: I choose to disable timer interrupt
        // but maybe there is a better way to handle this
    // @z222ye: Compared to disable interrupts, maybe we can just change priority 
        // of PendSV and SVC_Hander to be lower than timer interrupt
    // @z222ye: Or maybe we can use minimal critical sections with CPSID/CPSIE
    CPSID I
    
    // 2. Save R4-R11
    MRS R0, PSP
    STMDB R0!, {R4-R11}

    // 3. Save current task's updated PSP
    LDR R1, =g_current_task_idx
    LDR R2, [R1]
    LDR R3, =tcb_list
    MOV R4, #TCB_STRUCT_SIZE    // Replace hardcoded #24
    MLA R2, R2, R4, R3
    STR R0, [R2, #SP_OFFSET]    // Replace hardcoded #16

    // 4. Call scheduler
    PUSH {LR}           // Save EXC_RETURN
    BL scheduler
    POP {LR}            // Restore EXC_RETURN
    ISB

    // 5. Load new task's PSP
    LDR R1, =g_current_task_idx
    LDR R2, [R1]
    LDR R3, =tcb_list
    // R4 still has TCB_STRUCT_SIZE
    MLA R2, R2, R4, R3
    LDR R0, [R2, #SP_OFFSET] // Use your actual immediate value or .equ

    // 6. Restore R4-R11
    LDMIA R0!, {R4-R11}

    // 7. Update PSP
    MSR PSP, R0

    // 8. Enable interrupts
    // @z222ye: I choose to disable timer interrupt
        // but maybe there is a better way to handle this
    CPSIE I

    // 9. Exit exception
    BX LR

.size PendSV_Handler, . - PendSV_Handler // Optional: specify function size
