#include "system.h"
#include "dt.h"

void memcpy(uInt8* dest, uInt8* source, int count) {
  while (count-- > 0) {
    dest[count] = source[count];
  }
}

void memset(uInt8* des, uInt8 val, int count) {
  while (count-- > 0) {
    des[count] = val;
  }
}

void memcpyw(uInt16* des, uInt16* source, int count) {
  while (count-- > 0) {
    des[count] = source[count];
  }
}

void memsetw(uInt16* des, uInt16 val, int count) {
  while (count-- > 0) {
    des[count] = val;
  }
}

int strlen(const char* p) {
  int len = 0;
  while (p[len++] != '\0') {
    ;
  }
  return len - 1;
}

uInt8 readb(uInt16 addr) {
  uInt8 rv;
  // asm volatile ("inb %1, %0" : "=a" (rv) : "dN" (addr));
  asm volatile("inb %1, %0" : "=a" (rv) : "dN" (addr));
  return rv;
}

void writeb(uInt16 addr, uInt8 data) {
  asm volatile ("outb %1, %0" :: "dN" (addr), "a" (data));
}

int main() {
  // ignore the warning with vars.
  // we're literally running on a barebones
  // kernel/env here
  // the idea is that we should not return from main() in the case for 
  // an 'advanced' OS
  
  init_video();
  init_descriptor_tables();

  asm volatile ("INT $0x8"); 
  // theoretically, now I can keep 0x1F for logging, since it is not assigned

  for (;;);
}
