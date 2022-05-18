#!/bin/bash

if [[ -f ./hdd.img ]] ; then
    rm hdd.img
fi

sudo losetup -d /dev/loop0
sudo losetup -d /dev/loop1

dd if=/dev/zero of=hdd.img bs=1048576 count=1024

(echo g; echo "n p"; echo "1"; echo ""; echo "+512M"; echo "t 1"; echo "1"; echo "n p"; echo "2"; echo ""; echo ""; echo "t 2"; echo "2"; echo "20"; echo "w";) | fdisk hdd.img

sudo losetup -o $[2048*512] --sizelimit $[512*1024*1024] -f hdd.img

sudo mkfs.vfat -F 32 -n "EFI System" /dev/loop0

mkdir ./mnt
sudo mount /dev/loop0 ./mnt
sudo mkdir -p ./mnt/EFI/BOOT
sudo cp ./BOOTX64.EFI ./mnt/EFI/BOOT
sudo umount ./mnt
rmdir ./mnt

sudo losetup -o $[1050624*512] -f hdd.img
sudo mkfs.vfat -F 32 /dev/loop1

sudo losetup -d /dev/loop0
sudo losetup -d /dev/loop1

echo "Done"

