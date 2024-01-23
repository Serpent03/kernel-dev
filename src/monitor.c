#include "system.h"
#define WIDTH 80
#define HEIGHT 25
#define VGA_BADR 0xB8000 
#define CLR 0x0F20
#define CR 0xD
#define LF 0xA

uInt16 curx = 1;
uInt16 cury = 9;
uInt8 BGCOLOR = COL_BLK;
uInt8 FGCOLOR = COL_WHT;
uInt16* CURPIX = ((uInt16*)VGA_BADR);

void settc(uInt8 fg, uInt8 bg) {
  FGCOLOR = fg;
  BGCOLOR = bg;
}

uInt16 pixel_offset(uInt16 x, uInt16 y) {
  if ((0 < x && x <= WIDTH) && (0 < y && y <= HEIGHT)) {
    return ((y-1) * WIDTH) + x - 1;
  }
  return -1;
}

void setcursor() {
  // set the location of the cursor on the screen
  int loc = pixel_offset(curx, cury);
  writeb(0x3D4, 14); 
  writeb(0x3D5, loc >> 8);
  writeb(0x3D4, 15);  
  writeb(0x3D5, loc);
  // 0x3D4: control 'register'
  // 0x3D5: data 'register'
  // for some reason, 0x3D5 is of one byte: so we have to
  // call it twice to load two bytes. 
  // With value 14, we load in the high bits 
  // with value 15, we load in the low bits
}

void cls() {
  // clear out the screen
  int i = 0;
  curx = 1;
  cury = 1;
  setcursor();
  while (i++ < HEIGHT) {
    memsetw(CURPIX, CLR, WIDTH); 
    CURPIX += WIDTH;
  }
  CURPIX = ((uInt16*)VGA_BADR);
}

void cll(int y) {
  // clear out a specific line instead of the entire screen
  uInt16* CL = ((uInt16*)VGA_BADR) + pixel_offset(0, y);
  memsetw(CL, CLR, WIDTH);
}

void scroll(int n) {
  // scroll n lines to make space
  uInt16* CL = ((uInt16*)VGA_BADR);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      memcpyw(CL, CL+WIDTH, WIDTH);
      CL += WIDTH;
    }
    cury--;
    CL = ((uInt16*)VGA_BADR);
  }
  setcursor();
}

void init_video() {
  cls();
}

void putch(char c) {
  // put character at the current cursor posit. 1-indexed
  uInt16 loc = pixel_offset(curx, cury); 
  CURPIX = ((uInt16*)VGA_BADR) + loc;
  uInt16 attribute = BGCOLOR << 4 | FGCOLOR & 0xF;
  // TODO cursor CRLF and scroll
  if (c == LF) {
    cury++;
    curx = 1;
    setcursor();
    return;
  } else if (c == CR) {
    curx = 1;
    setcursor();
    return;
  } else {
    curx++;
  }
  *CURPIX = c | (attribute << 8);
  setcursor();
  // so this *CURPIX is pointing directly to a memory address.
  // changing the value at the memory address for a pixel means
  // that we directly change the way its rendered, thus we do 
  // not need any additional interrupts than the "hardware"
  // clock itself.
}

void puts(char* s) {
  char c;
  while (c = *s++) {
      putch(c);
  }
}

void puti(int s) {
  int num = 0;
  while (s > 0) {
    num *= 10;
    num += s % 10;
    s /= 10;
  }
  while (num > 0) {
    putch(num % 10 + '0');
    num /= 10;
  }
}

char int2hex(int n) {
  if (n > 9) {
    return (n % 10) + 'A';
  } else {
    return n + '0';
  }
}

void puth(int s) {
  char num[8];
  int ptr = -1;
  for (int i = 0; i < 8; i++) {
    num[i] = '0';
  }
  while (s > 0) {
    ptr++;
    num[ptr] = int2hex(s % 16);
    s /= 16;
  }
  ptr = (ptr % 2 == 0) ? ptr + 1 : ptr;
  // ptr begins at -1. It's always going to be 1 less than
  // required - so we check if the ptr is even, and then
  // increment, instead of doing the opposite
  puts("0x"); 
  while (ptr >= 0) {
    putch(num[ptr--]);
  }
}




