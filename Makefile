kernel.bin: main.o start.o
	ld -T link.ld -o kernel.bin main.o start.o
start.o:start.asm
	nasm -f elf64 -o start.o start.asm
main.o: main.c 
	gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o main.o main.c
clean:
	rm -f *.o *.bin
