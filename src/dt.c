#include "system.h"
#include "dt.h"
#include "isrs.h"

#define GDT_ENTRIES 3
#define IDT_ENTRIES 256

gdt_entry_t gdt_entries[GDT_ENTRIES];
gdt_ptr_t gp;

idt_entry_t idt_entries[IDT_ENTRIES]; 
idt_ptr_t ip;

void init_descriptor_tables() {
  puts("INIT GDT\n");
  init_gdt();
  puts("INIT IDT\n");
  init_idt();
}

void init_gdt() {
  gp.limit = (sizeof(gdt_entry_t) * GDT_ENTRIES) - 1;
  gp.base = (uInt32)&gdt_entries;

  gdt_set_gate(0, 0, 0, 0, 0);
  gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
  gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

  gdt_flush();
}

void init_idt() {

  ip.limit = (sizeof(idt_entry_t) * IDT_ENTRIES) - 1;
  ip.base = (uInt32)&idt_entries;
  
  // set the entire IDT table to 0 before initializing
  memset((void*)&idt_entries, 0, sizeof(idt_entry_t) * IDT_ENTRIES);
 
  isrs_install();
  idt_load();
}

void gdt_set_gate(Int32 num, uInt32 base, uInt32 limit, uInt8 access, uInt8 gran) {
  gdt_entries[num].base_low = (base & 0xFFFF);
  gdt_entries[num].base_middle = (base >> 16) & 0xFF;
  gdt_entries[num].base_high = (base >> 24) & 0xFF;

  gdt_entries[num].limit_low = (limit & 0xFFFF);
  gdt_entries[num].granularity = ((limit >> 16) & 0x0F);

  gdt_entries[num].granularity |= (gran & 0xF0);
  gdt_entries[num].access = access;
}

void idt_set_gate(uInt8 num, uInt32 base, uInt16 sel, uInt8 flags) {
  idt_entries[num].base_low = base & 0xFFFF;
  idt_entries[num].base_high = (base >> 16) & 0xFFFF;

  idt_entries[num].sel = sel;
  idt_entries[num].always0 = 0;
  idt_entries[num].flags = flags;
}








