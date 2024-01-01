#ifndef __SYSTEM_H
#define __SYSTEM_H
#endif // ndef __SYSTEM_H

typedef unsigned char uInt8;
typedef char Int8;
typedef unsigned short int uInt16;
typedef short int Int16;
typedef unsigned int uInt32;
typedef int Int32;

// MISC
extern void memcpy(uInt8* dest, uInt8* source, int count);
extern void memset(uInt8* des, uInt8 val, int count);
extern void memcpyw(uInt16* dest, uInt16* source, int count);
extern void memsetw(uInt16* des, uInt16 val, int count);
extern int strlen(const char* p);
extern uInt8 readb(uInt16 addr);
extern void writeb(uInt16 addr, uInt8 data);

// VIDEO
#define COL_BLK 0x0
#define COL_WHT 0xF
#define COL_RED 0x4
#define COL_GRN 0x2
#define COL_BLU 0x1

extern void cls();
extern void cll(int y); // clear line
extern void putch(char c);
extern void puts(char* s); // string
extern void puti(int s); // integer
extern void puth(int s); // hexadecimal
extern void settc(uInt8 fg, uInt8 bg); // colors
extern void scroll(int n); // scroll n lines
extern void init_video();
extern uInt16 pixel_offset(uInt16 x, uInt16 y);

// DEBUG
// could print all the registers. call INT 0x31?
