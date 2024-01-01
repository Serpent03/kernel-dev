; this handles the IDT setup
global idt_load
extern ip
idt_load:
  lidt    [ip]
  ret

global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31

; ISR          DESCRIPTION            POPS ERR_CODE
; 0	  Division By Zero Exception	          No
; 1	  Debug Exception	                      No
; 2	  Non Maskable Interrupt Exception	    No
; 3	  Breakpoint Exception	                No
; 4	  Into Detected Overflow Exception	    No
; 5	  Out of Bounds Exception	              No 
; 6	  Invalid Opcode Exception	            No
; 7	  No Coprocessor Exception	            No
; 8	  Double Fault Exception	              Yes
; 9	  Coprocessor Segment Overrun Exception	No
; 10  Bad TSS Exception	                    Yes
; 11	Segment Not Present Exception	        Yes
; 12	Stack Fault Exception	                Yes
; 13	General Protection Fault Exception	  Yes
; 14	Page Fault Exception	                Yes
; 15	Unknown Interrupt Exception	          No
; 16	Coprocessor Fault Exception	          No
; 17	Alignment Check Exception (486+)	    No
; 18	Machine Check Exception (P/586+)      No
; 19 to 31	Reserved Exceptions	            No

; Since not every interrupt service routine is popping error codes,
; we will have to push out dummy error codes(that is, a value of 0)
; so that uniformity is maintained in the stack, when we later access it

extern fault_handler ; fault_handler is defined in isrs.c
isr_cstub:
  pusha 
  ; push all GP registers on the stack: eax, ebx, ecx, 
  ; https://faydoc.tripod.com/cpu/pusha.htm

  push    ds    
  push    es
  push    fs
  push    gs

  mov     ax, 0x10
  mov     ds, ax
  mov     es, ax
  mov     fs, ax
  mov     gs, ax

  mov     eax, esp
  push    eax 
  ; we push the value of the stack pointer in the stack
  ; this will help later - it will allow us to create a struct and utilize
  ; it like a pointer to a struct in the fault_handler program as the arg
  ; mov     eax, fault_handler
  call    fault_handler ; load the address of the fault_handler, and then call it

  pop     eax
  pop     gs
  pop     fs
  pop     es
  pop     ds

  popa ; pops of all GP registers
  add     esp, 8 
  ; we stored two values in the stack: OPCODE and ISR_NUM. We simply 'clear'
  ; those away: we 'decrement' the top 

  ; iret: interrupt return. restore CPU so it continues doing whatever it was doing
  ; https://docs.oracle.com/cd/E19455-01/806-3773/instructionset-75/index.html 
  cli
  iret 

isr0:
  cli ; we disable interrupts so that regular requests can't mutate the kernel
  push    byte 0 ; dummy error code
  push    byte 0 ; ISR number
  jmp     isr_cstub

isr1:
  cli
  push    byte 0
  push    byte 1
  jmp isr_cstub

isr2:
  cli
  push    byte 0
  push    byte 2
  jmp isr_cstub


isr3:
  cli
  push    byte 0
  push    byte 3
  jmp isr_cstub

isr4:
  cli
  push    byte 0
  push    byte 4
  jmp isr_cstub

isr5:
  cli
  push    byte 0
  push    byte 5
  jmp isr_cstub

isr6:
  cli
  push    byte 0
  push    byte 6
  jmp isr_cstub

isr7:
  cli
  push    byte 0
  push    byte 7
  jmp isr_cstub

isr8:
  cli
  push    byte 8 ; no error code is pushed here - the interrupt automatically does that
  jmp isr_cstub

isr9:
  cli
  push    byte 0
  push    byte 9
  jmp isr_cstub

isr10:
  cli
  push    byte 10
  jmp isr_cstub

isr11:
  cli
  push    byte 11
  jmp isr_cstub

isr12:
  cli
  push    byte 12
  jmp isr_cstub

isr13:
  cli
  push    byte 13
  jmp isr_cstub

isr14:
  cli
  push    byte 14
  jmp isr_cstub

isr15:
  cli
  push    byte 0
  push    byte 15
  jmp isr_cstub

isr16:
  cli
  push    byte 0
  push    byte 16
  jmp isr_cstub

isr17:
  cli
  push    byte 0
  push    byte 17
  jmp isr_cstub

isr18:
  cli
  push    byte 0
  push    byte 18
  jmp isr_cstub

isr19:
  cli
  push    byte 0
  push    byte 19
  jmp isr_cstub

isr20:
  cli
  push    byte 0
  push    byte 20
  jmp isr_cstub

isr21:
  cli
  push    byte 0
  push    byte 21
  jmp isr_cstub

isr22:
  cli
  push    byte 0
  push    byte 22
  jmp isr_cstub

isr23:
  cli
  push    byte 0
  push    byte 23
  jmp isr_cstub

isr24:
  cli
  push    byte 0
  push    byte 24
  jmp isr_cstub

isr25:
  cli
  push    byte 0
  push    byte 25
  jmp isr_cstub

isr26:
  cli
  push    byte 0
  push    byte 26
  jmp isr_cstub

isr27:
  cli
  push    byte 0
  push    byte 27
  jmp isr_cstub

isr28:
  cli
  push    byte 0
  push    byte 28
  jmp isr_cstub

isr29:
  cli
  push    byte 0
  push    byte 29
  jmp isr_cstub

isr30:
  cli
  push    byte 0
  push    byte 30
  jmp isr_cstub

isr31:
  cli
  push    byte 0
  push    byte 31
  jmp isr_cstub


