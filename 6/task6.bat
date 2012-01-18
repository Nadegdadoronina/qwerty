gcc -c -m32 -march=i386 -std=c99 main.c
ld --oformat elf32-i386 -m elf_i386 -Tlink.ld main.o
objcopy -O binary a.out b.out
nasm load.asm 
cat load b.out  > res
rm main.o a.out b.out load