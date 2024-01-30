# TinyThread

A small, simple RTOS(transitioning to GPOS) made with the use of C and assembly. 

## Pre-Requisites
- CC/GCC
- nasm
- GNU make
- qemu

On linux systems, run the command:
```bash 
sudo apt install make
sudo apt install nasm
sudo apt-get install qemu-system
``` 

## Installation

Clone the repository onto your local machine using git:

```bash
git clone https://github.com/Serpent03/kernel-dev.git
```

## Overview

```/src``` holds all the source codes. ```sk.bash``` holds the commands to run the kernel image on the ```qemu-emulator```. Various files like `system.h`(common header files), `monitor.c`(graphics drivers), `dt.h`(header files for descriptor tables) hold information necessary to switch the kernel into protected mode.

## Future Ideas / TODOs

- Implement user and user space, along with ring 2 and ring 3 privileges.
- Implement network packets and ethernet drivers/sockets.
- Implement shell based OS operations.
- Implement CHS hard disk read/write.
