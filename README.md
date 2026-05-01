# Monty Bytecode Interpreter

A C interpreter for **Monty 0.98** bytecode — a stack/queue-based virtual machine that reads `.m` files line by line, parses opcodes, and executes them using a doubly linked list data structure.

## Overview

Monty 0.98 is a simple assembly-like language where programs operate on a stack (LIFO) or queue (FIFO). This interpreter implements the full Monty 0.98 specification in C, managing a doubly linked list as the underlying data structure and dispatching 15 opcodes via a function-pointer lookup table.

## Features

- **Doubly Linked List Stack/Queue** — The core data structure supports both LIFO (stack) and FIFO (queue) semantics
- **15 Opcodes Implemented** — Full coverage of the Monty 0.98 instruction set
- **Robust Error Handling** — Graceful exits with descriptive messages and line numbers for:
  - Missing or unreadable bytecode files
  - Unknown instructions
  - Missing or invalid `push` arguments
  - Stack underflow (pop, swap, add, sub, div, mul, mod on empty/short stacks)
  - Division by zero (`div`, `mod`)
  - Out-of-range ASCII values (`pchar`)
  - `malloc` failures
- **Comments & Blank Lines** — Ignores lines starting with `#` and empty lines
- **Betty Coding Style** — Follows Holberton/ALX C coding standards

## Opcodes

| Opcode | Description |
|--------|-------------|
| `push <int>` | Pushes an integer onto the stack |
| `pall` | Prints all values on the stack |
| `pint` | Prints the value at the top of the stack |
| `pop` | Removes the top element of the stack |
| `swap` | Swaps the top two elements of the stack |
| `add` | Adds the top two elements (result stored in second) |
| `sub` | Subtracts the top element from the second |
| `mul` | Multiplies the top two elements |
| `div` | Divides the second element by the top |
| `mod` | Computes the remainder of second % top |
| `nop` | No operation |
| `pchar` | Prints the character at the top of the stack (ASCII) |
| `pstr` | Prints the string starting at the top of the stack (stops at non-printable or 0) |
| `rotl` | Rotates the stack so the top becomes the bottom |
| `rotr` | Rotates the stack so the bottom becomes the top |

## Architecture

```
┌───────────────────────────────────────────────┐
│                  main()                        │
│  ┌──────────┐  ┌───────────┐  ┌────────────┐  │
│  │Read line │→ │parse_line │→ │get_function│  │
│  │from .m   │  │(tokenize, │  │(dispatch to│  │
│  │file      │  │validate)  │  │opcode fn)  │  │
│  └──────────┘  └───────────┘  └──────┬─────┘  │
│                                      │         │
│              ┌───────────────────────┼───────┐ │
│              ▼                       ▼       ▼ │
│         ┌─────────┐  ┌────────────────────────┐│
│         │Stack Ops│  │   Arithmetic & I/O Ops ││
│         │push/pop │  │add/sub/mul/div/mod/    ││
│         │swap/rot │  │pint/pall/pchar/pstr/nop││
│         └─────────┘  └────────────────────────┘│
└───────────────────────────────────────────────┘
```

## File Structure

| File | Description |
|------|-------------|
| `monty.c` | Main entry point — file I/O, line-by-line execution loop |
| `monty.h` | Header with type definitions (`stack_t`, `instruction_t`) and function prototypes |
| `parse_line.c` | Tokenizes a line, validates opcode, extracts push argument |
| `check_op_code.c` | Validates whether a string is a known Monty opcode |
| `requires_argument.c` | Checks if an opcode requires an integer argument |
| `get_function.c` | Function-pointer dispatcher mapping opcodes to handlers |
| `global.c` | Global variable for push argument value |
| `is_number.c` | Validates that a string is a valid integer |
| `push.c` | Pushes an integer onto the stack (doubly linked list insertion) |
| `pop.c` | Removes the top stack element |
| `swap.c` | Swaps top two elements |
| `add.c` / `sub.c` / `mul.c` / `div.c` / `mod.c` | Arithmetic operations on top two elements |
| `pall.c` / `pint.c` | Print all / print top of stack |
| `pchar.c` / `pstr.c` | Print character / print string from stack |
| `rotl.c` / `rotr.c` | Rotate stack left (top→bottom) / right (bottom→top) |
| `nop.c` | No-operation |
| `bf/` | Sample Brainfuck programs compiled to Monty bytecode |

## Requirements

- GCC compiler
- Linux/Unix environment
- POSIX-compliant system headers

## Build

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

## Usage

```bash
./monty <filename.m>
```

### Example

Given a file `example.m`:
```
push 1
push 2
push 3
pall
add
pint
pop
pall
```

```bash
$ ./monty example.m
3
2
1
5
2
1
```

## Error Handling

The interpreter exits with `EXIT_FAILURE` and prints to `stderr` for:

- **Usage**: `USAGE: monty file`
- **File open**: `Error: Can't open file <filename>`
- **Unknown opcode**: `L<n>: unknown instruction <opcode>`
- **Missing push argument**: `L<n>: usage: push integer`
- **Stack too short**: `L<n>: can't <op>, stack too short`
- **Empty stack**: `L<n>: can't <op>, stack empty`
- **Division by zero**: `L<n>: division by zero`
- **Out of range**: `L<n>: can't pchar, value out of range`
- **Malloc failure**: `Error: malloc failed`

## Tech Stack

- **Language**: C (C89/C90 standard)
- **Data Structures**: Doubly linked list (`stack_t`)
- **I/O**: `FILE*`, `fgets`, `fopen`, `fprintf`, `printf`, `putchar`
- **Memory**: `malloc`, `free`, `atoi`
- **String**: `strtok`, `strcmp`, `strdup`

## Coding Standard

This project follows the **Betty C coding style**:

- Functions are limited to a specific line count
- Variables are declared at the top of blocks
- Consistent brace placement and indentation
- Descriptive function and variable names
- Documentation comments for all functions

## Author

**Natnael Samson** — [Nattyy-1](https://github.com/Nattyy-1)
