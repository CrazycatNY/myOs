kernel.bin: main.o start.o scrn.o gdt.o
	ld -m elf_i386 -T link.ld -o kernel.bin start.o main.o scrn.o gdt.o
start.o:start.asm
	nasm -f elf32 -o start.o start.asm
main.o: main.c 
	gcc -m32 -Wall -O -fno-pie -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o main.o main.c
scrn.o: scrn.c
	gcc -m32 -Wall -O -fno-pie -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o scrn.o scrn.c
gdt.o: gdt.c 
	gcc -m32 -Wall -O -fno-pie -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o gdt.o gdt.c 
clean:
	rm -f *.o *.bin
