section .text

add:
  add   eax, ebx
  ret

sub:
  sub   eax, ebx
  ret

mul:
  mul   ebx
  ret

div:
  div   ebx ; eax / eXX; Q: eax, R: edx
  ret

