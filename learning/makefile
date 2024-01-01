asmcc = nasm
asmflags = -felf32
ld = ld
ldflags = -m elf_i386
bash = bash -c
externfiles = utils.asm math.asm

main: hello.o
	$(ld) $(ldflags) -o main hello.o

hello.o: hello.asm $(externfiles)
	$(asmcc) $(asmflags) hello.asm

clean:
	$(bash) "rm *.o"
