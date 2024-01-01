MBOOT_PAGE_ALIGN    equ 1<<0
MBOOT_MEM_INFO      equ 1<<1
MBOOT_HEADER_MAGIC  equ 0x1BADB002 
; it seems like a magic number: random, but to define
; this kernel as GRUB compatible

MBOOT_HEADER_FLAGS  equ MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO
MBOOT_CHECKSUM      equ -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)

[BITS 32] ; define instruction length

global mboot ; entry point, so we can access from C
extern code 
extern bss 
extern end ; code, bss and end sections are all defined 'somewhere'

; mboot is a location in memory - nothing more. what we're doing here is bunching 
; together all the necessary information: code, bss, start, end, CHECKSUM, and letting
; the kernel know where it is all stored, so we can easily access it
mboot: 
  dd MBOOT_HEADER_MAGIC ; GRUB(bootloader) searches for HEADER_MAGIC on each 4 byte
                        ; interval. so we allocate a DWORD(32-bit = 4byte) space for it
  
  dd MBOOT_HEADER_FLAGS   
  dd MBOOT_CHECKSUM 

  dd mboot ; memory address of mboot
  dd code ; memory address of .text(code) section
  dd bss ; memory address of .data section
  dd end ; memory address of the end of kernel file
  dd start ; memory address of our initial entry - where the kernel actually begins

  ; these might be useful for the GDT later on!



global start 
extern main ; main exists somewhere out there(in reality, it's the main() from C)

start:
  call    main ; call the main() function

  cli ; disable interrupts
  jmp     $ 
  ; the CPU will keep jumping to our present addr - inf. loop

