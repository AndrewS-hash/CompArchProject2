cls
del *.o
del *.disass
del *.srec
del *.ihex
del *.rom

riscv64-unknown-elf-gcc -c -mabi=ilp32 -march=rv32im boot.s -O3 -o boot.o
riscv64-unknown-elf-gcc -c -mabi=ilp32 -march=rv32im -DUSE_MYSTDLIB -DTIME -DRISCV -O3 stdlib.c -o stdlib.o
riscv64-unknown-elf-gcc -c -mabi=ilp32 -march=rv32im -DUSE_MYSTDLIB -DTIME -DRISCV -O3 main.c -o main.o
riscv64-unknown-elf-ld -nostdlib -T rv32im.ls boot.o stdlib.o main.o -o bl.elf
riscv64-unknown-elf-objcopy -O binary bl.elf bl.bin
riscv64-unknown-elf-objcopy -O srec bl.elf bl.srec
riscv64-unknown-elf-objcopy -O ihex bl.elf bl.ihex
riscv64-unknown-elf-objcopy -R rom bl.elf bl.rom
riscv64-unknown-elf-objdump -D bl.elf > bl.disass




