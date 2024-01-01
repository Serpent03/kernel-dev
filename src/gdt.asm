; this handles the GDT setup
global gdt_flush
extern gp
gdt_flush:
  lgdt    [gp]

  mov     ax, 0x10
  mov     ds, ax
  mov     es, ax
  mov     fs, ax
  mov     gs, ax
  mov     ss, ax
  jmp     0x08:.flush ; long jump
.flush:
  ret ; return control back to C


