#include "system.h"
// these are the interrupt service routines. We'll define them using assembly
// the functions for these will be defined in the assemvly file. we'll get 
// their function address, and then the kernel will know where exactly to
// go in the case if an error occurs. 
//
// at the location of these functions, we will push the error code and the 
// interrupt code. we'll then proceed to a wrapper, which will 
// invoke a C function to deal with all the stuff

typedef struct registers {
  uInt32 gs, fs, es, ds;
  uInt32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
  uInt32 interrupt_code, err_code;
  uInt32 eip, cs, eflags, useresp, ss;
} register_t;

extern void fault_handler(register_t regs);

extern void isrs_install(); // called from dt.c when initializing tables
extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
