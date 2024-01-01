section .text
global _start

; it looks like the TETRIS_OS project was also built
; on top of the qEMU base. I saw a bunch of matching
; kernel interrupt calls - which is interesting

; I think I will have to look into this tomorrow, 
; it seems to me we're right in the smack dab, middle of
; of a ring 0, very basic kernel system

; one of the confusions I have is regarding the 
; Von Neumann architecture. RAM and ROM co-existing, so 
; to speak - the thought is very complex for some reason

_start:
  jmp $ ; infinitely jump to current memory address
  ; the ($ - $$) apparently somehow understands the padding
  ; above this line
  times 510 - ($-$$) db 0
  db 0x55, 0xAA
