// pendsv_handler.s
.syntax unified
.thumb
.global PendSV_Handler  // Make the symbol visible to the linker
.type PendSV_Handler, %function // Specify it's a function

PendSV_Handler:
    // 1. Disable interrupts (optional)
    // CPSID I

    // 2. Save R4-R11
    MRS R0, PSP
    STMDB R0!, {R4-R11}

    // 3. Save current task's updated PSP
    LDR R1, =g_current_task_idx
    LDR R2, [R1]
    LDR R3, =tcb_list
    // Assuming TCB_STRUCT_SIZE and OFFSET_SP_IMM are defined elsewhere
    // or you use .equ directives here if they are constants.
    // For simplicity, let's assume they are accessible or you hardcode for now.
    // You might need to pass these as arguments or load them if they are dynamic.
    // For now, let's use symbolic constants that your assembler would resolve
    // or that you define with .equ
    // .equ TCB_STRUCT_SIZE_ASM, 20 // Example, ensure this matches your C define
    // .equ OFFSET_SP_IMM_ASM, 16   // Example, ensure this matches your C define
    MOV R4, #20 // Use your actual immediate value or .equ
    MLA R2, R2, R4, R3
    STR R0, [R2, #16] // Use your actual immediate value or .equ

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
    LDR R0, [R2, #16] // Use your actual immediate value or .equ

    // 6. Restore R4-R11
    LDMIA R0!, {R4-R11}

    // 7. Update PSP
    MSR PSP, R0

    // 8. Enable interrupts (if disabled)
    // CPSIE I

    // 9. Exit exception
    BX LR

.size PendSV_Handler, . - PendSV_Handler // Optional: specify function size
