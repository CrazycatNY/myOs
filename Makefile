kernel.bin: main.o start.o scrn.o
	ld -T link.ld -o kernel.bin main.o start.o scrn.o
start.o:start.asm
	nasm -f elf64 -o start.o start.asm
scrn.o:scrn.o
	gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o scrn.o scrn.c
main.o: main.c 
	gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o main.o main.c
clean:
	rm -f *.o *.bin
