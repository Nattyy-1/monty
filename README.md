Monty

Simple interpreter for Monty 0.98 bytecode. The program reads a .m file line by line, parses each opcode, and performs stack or queue operations using a doubly linked list.

How to compile
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

How to run
./monty file.m

What it does

Implements stack (LIFO) and queue (FIFO)

Handles opcodes like push, pall, pop, etc.

Uses a doubly linked list

Stops on errors (bad file, bad opcode, malloc failure)

Files

monty.c

monty.h

opcode function files

Author

Natnael Samson
