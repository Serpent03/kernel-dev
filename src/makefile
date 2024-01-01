infiles=boot.asm gdt.asm idt.asm main.c monitor.c dt.c isrs.c
sources=boot.o gdt.o idt.o main.o monitor.o dt.o isrs.o
CFLAGS=-nostdlib -nostdinc -m32 -fno-builtin -fomit-frame-pointer -finline-functions -I./include
LDFLAGS=-m elf_i386 -s -T linker.ld
ASFLAGS= -felf32

all: kernel.bin

$(sources): $(infiles)
	nasm $(ASFLAGS) boot.asm -o boot.o
	nasm $(ASFLAGS) gdt.asm -o gdt.o
	nasm $(ASFLAGS) idt.asm -o idt.o
	gcc $(CFLAGS) -c -o main.o main.c 
	gcc $(CFLAGS) -c -o dt.o dt.c 
	gcc $(CFLAGS) -c -o monitor.o monitor.c 
	gcc $(CFLAGS) -c -o isrs.o isrs.c 

kernel.bin: $(sources) *.c
	ld $(LDFLAGS) -o kernel.bin $(sources)

clean:
	-rm *.o kernel.bin *.txt
