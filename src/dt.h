#include "system.h"

typedef struct  {
  uInt16 limit_low;
  uInt16 base_low;
  uInt8 base_middle;
  uInt8 access;
  uInt8 granularity;
  uInt8 base_high;
} __attribute__((packed)) gdt_entry_t;

typedef struct {
  // the address to this is what would  be feeded to
  // the LGDT operation for the kernel
  uInt16 limit;
  uInt32 base;
} __attribute__((packed)) gdt_ptr_t;

typedef struct {
  uInt16 base_low;
  uInt16 sel;
  uInt8 always0; // this segment is always 0
  uInt8 flags;
  uInt16 base_high;
} __attribute__ ((packed)) idt_entry_t;

typedef struct {
  uInt16 limit;
  uInt32 base;
} __attribute__((packed)) idt_ptr_t;

extern void init_descriptor_tables();
extern void gdt_flush(); // defined in boot.asm
extern void idt_load(); // defined in boot.asm

extern void init_gdt();
extern void init_idt();
extern void gdt_set_gate(Int32 num, uInt32 base, uInt32 limit, uInt8 access, uInt8 gran);                              
extern void idt_set_gate(uInt8 num, uInt32 base, uInt16 sel, uInt8 flags);

