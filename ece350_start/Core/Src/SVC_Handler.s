    .syntax unified
    .thumb

    .global SVC_Handler
    .extern SVC_Handler_Main
    .type SVC_Handler, %function
    .type SVC_Handler_Main, %function

// SVC_Handler: Only calls SVC_Handler_Main with the correct stack pointer
SVC_Handler:
    tst lr, #4              // Test EXC_RETURN bit 2 to determine stack pointer
    ite eq
    mrseq r0, msp           // If 0, use MSP
    mrsne r0, psp           // If 1, use PSP
    b SVC_Handler_Main      // Branch to C handler (r0 = svc_args)