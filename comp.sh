#!/bin/bash

start_time=$(date +%s%N)  # Capture the start time in nanoseconds

printf "removing dir build...\n"
rm -f build
printf "making dir build...\n"
mkdir -p build
printf "done\n"
printf "entering build...\n"
cd build
printf "done\n"
printf "as\n"
i686-elf-as ../boot.s -o boot.o
printf "done\n"
printf "g++\n"
i686-elf-g++ -c ../kernel.cpp ../drivers/io.h ../drivers/io.cpp ../drivers/keyboard.cpp ../drivers/keyboard.h ../drivers/timer.cpp ../drivers/timer.h -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -fpermissive
printf "done\n"
printf "gcc\n"
i686-elf-gcc -T ../linker.ld -o grub/boot/latest.bin -ffreestanding -O2 -nostdlib boot.o io.o keyboard.o kernel.o timer.o -lgcc
printf "done\n"
printf "making dir grub...\n"
mkdir -p grub
printf "done\n"
printf "entering grub...\n"
cd grub
printf "done\n"
printf "creating boot/grub\n"
printf "creating boot\n"
mkdir -p boot/grub
printf "done\n"
printf "entering boot...\n"
cd boot
printf "done\n"
printf "creating grub...\n"
mkdir -p grub
printf "done\n"
printf "entering grub...\n"
cd grub
printf "done\n"
printf "done\n"
printf "creating grub.cfg\n"
cat <<EOS > grub.cfg
menuentry "pitanga" {
    multiboot /boot/latest.bin
}
EOS
printf "done\n"
printf "entering ../..\n"
cd ../..
printf "done\n"

end_time=$(date +%s%N)  # Capture the end time in nanoseconds
elapsed_time=$((end_time - start_time))
elapsed_seconds=$((elapsed_time / 1000000000))
elapsed_milliseconds=$(( (elapsed_time / 1000000) % 1000))

hours=$((elapsed_seconds / 3600))
minutes=$(( (elapsed_seconds % 3600) / 60))
seconds=$((elapsed_seconds % 60))

printf "pitanga kernel compiled successfully in %02d:%02d:%02d.%03d\n" $hours $minutes $seconds $elapsed_milliseconds

read -p "kernel compiled, make pitanga basic edition (bootable)? (y/n): " response

response=$(echo "$response" | tr '[:upper:]' '[:lower:]')

if [[ "$response" == "y" ]]; then
    printf "making bootable image\n"
else
    exit
fi

printf "grub-mkrescue\n"
grub-mkrescue -o latest.iso .
printf "done\n"
printf "entering ../..\n"
cd ../..
printf "done\n"

read -p "run build in qemu? (y/n): " response

response=$(echo "$response" | tr '[:upper:]' '[:lower:]')

if [[ "$response" == "y" ]]; then
    printf "qemu-system-x86_64\n"
    p=$(pwd)
    qemu-system-x86_64 -cdrom "$p/build/grub/latest.iso"
else
    printf "done\n"
fi

