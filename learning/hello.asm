%include 'utils.asm'
%include 'math.asm'

section .data
  ; CR => 0xD
  ; LF => 0xA
  
  filename db "readme.bin", 0xA
  msg db "Hello, world!", 0xA, 0x0

section .text
global _start


_start:
  mov ecx, 0777o
  mov ebx, filename
  mov eax, 8 ; OPCODE: creat_file. eax <= file descriptor
  INT 0x80

  push eax ; stack
  mov eax, msg

  call strlen
  mov ecx, msg
  pop ebx ; ebx <= eax from stack
  mov eax, 4 ; OPCODE: write
  INT 0x80

  mov ecx, 0 ; readonly flag
  mov ebx, filename
  mov eax, 5 ; OPCODE: open. eax <= file descriptor
  INT 0x80

  call iprintlf

  mov ebx, eax ; move file descriptor
  mov eax, 5 ; OPCODE: close
  INT 0x80


exit: ; just define an exit section for convenience
  call finished
  ; so it seems like 80h is an interrupt code,
  ; which then forces the kernel to look at 
  ; all the relevant registers: edx, ecx, etc.

  ; which also means that until I call int 80h,
  ; the kernel will NOT execute anything at all

