#!/bin/bash
clear
cd ./src
make && mv ./kernel.bin ../
make clean
cd ..
qemu-system-i386 -kernel ./kernel.bin
# make && qemu-system-i386 -cpu qemu32 -kernel ./kernel.bin -d cpu > serial.txt 2>&1
# echo "$(tail -18 serial.txt)" > out.txt
