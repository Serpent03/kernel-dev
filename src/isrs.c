#include "isrs.h"
#include "dt.h"
#include "system.h"

void isrs_install() {
  idt_set_gate(0, (uInt32)isr0, 0x08, 0x8E);
  idt_set_gate(1, (uInt32)isr1, 0x08, 0x8E);
  idt_set_gate(2, (uInt32)isr2, 0x08, 0x8E);
  idt_set_gate(3, (uInt32)isr3, 0x08, 0x8E);
  idt_set_gate(4, (uInt32)isr4, 0x08, 0x8E);
  idt_set_gate(5, (uInt32)isr5, 0x08, 0x8E);
  idt_set_gate(6, (uInt32)isr6, 0x08, 0x8E);
  idt_set_gate(7, (uInt32)isr7, 0x08, 0x8E);
  idt_set_gate(8, (uInt32)isr8, 0x08, 0x8E);
  idt_set_gate(9, (uInt32)isr9, 0x08, 0x8E);
  idt_set_gate(10, (uInt32)isr10, 0x08, 0x8E);
  idt_set_gate(11, (uInt32)isr11, 0x08, 0x8E);
  idt_set_gate(12, (uInt32)isr12, 0x08, 0x8E);
  idt_set_gate(13, (uInt32)isr13, 0x08, 0x8E);
  idt_set_gate(14, (uInt32)isr14, 0x08, 0x8E);
  idt_set_gate(15, (uInt32)isr15, 0x08, 0x8E);
  idt_set_gate(16, (uInt32)isr16, 0x08, 0x8E);
  idt_set_gate(17, (uInt32)isr17, 0x08, 0x8E);
  idt_set_gate(18, (uInt32)isr18, 0x08, 0x8E);
  idt_set_gate(19, (uInt32)isr19, 0x08, 0x8E);
  idt_set_gate(20, (uInt32)isr20, 0x08, 0x8E);
  idt_set_gate(21, (uInt32)isr21, 0x08, 0x8E);
  idt_set_gate(22, (uInt32)isr22, 0x08, 0x8E);
  idt_set_gate(23, (uInt32)isr23, 0x08, 0x8E);
  idt_set_gate(24, (uInt32)isr24, 0x08, 0x8E);
  idt_set_gate(25, (uInt32)isr25, 0x08, 0x8E);
  idt_set_gate(26, (uInt32)isr26, 0x08, 0x8E);
  idt_set_gate(27, (uInt32)isr27, 0x08, 0x8E);
  idt_set_gate(28, (uInt32)isr28, 0x08, 0x8E);
  idt_set_gate(28, (uInt32)isr29, 0x08, 0x8E);
  idt_set_gate(29, (uInt32)isr30, 0x08, 0x8E);
  idt_set_gate(31, (uInt32)isr31, 0x08, 0x8E);
}

void fault_handler(register_t regs) {
  putch('\n');
  puti(regs.err_code);
  for (;;);
  // TODO handle the errors here 
}
