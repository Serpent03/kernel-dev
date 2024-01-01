section .data
  LF db 0xA, 0x0
  CR db 0xD

section .text
strlen:
  ; mov the string address on eax in ebx
  push ebx ; push ebx on the stack to preserve
  mov ebx, eax

nextchar:
  ; increment until we find '\0'
  cmp byte[eax], 0
  jz setlen
  inc eax
  jmp nextchar

setlen:
  ; get strlen by checking the difference in the location
  ; of the address registers
  sub eax, ebx
  mov edx, eax
  pop ebx ; pop from stack 
  ret ; ret back to where this was called

sprint:
  ; at the entry, eax is already set to the str
  push ecx
  mov ecx, eax
  call strlen
  ; ecx has been already set
  mov ebx, 1
  mov eax, 0x04
  
  INT 80h
  pop ecx
  ret

sprintlf:
  call sprint
  push eax ; preserve eax
  mov eax, LF ; put in the LF character
  call sprint
  pop eax
  ret

iprintlf:
  call iprint
  push eax
  mov eax, LF
  call sprint
  pop eax
  ret

iprint:
  push eax ; div, carrier
  push ecx ; counter
  push edx ; ascii
  push esi ; dividend
  mov ecx, 0

divloop:
  inc ecx
  mov edx, 0
  mov esi, 10 ; base 10
  idiv esi ; edi <= eax % esi ; eax <= eax / esi
  add edx, 48
  push edx ; push this in the stack. we'll esp: LINE 73
  cmp eax, 0
  jnz divloop

printloop:
  dec ecx
  mov eax, esp ; put the num on the stack here
  call sprint
  pop eax
  cmp ecx, 0
  jnz printloop

  pop esi
  pop edx
  pop ecx
  pop eax

  ret

finished:
  mov ebx, 0
  mov eax, 1
  INT 80h
  ret
