#include "monty.h"

/**
 * check_op_code - checks if an opcode is valid
 * @opcode: the opcode string to check
 *
 * Return: 0 if valid, 1 if invalid
 */
int check_op_code(char *opcode)
{
	if (strcmp(opcode, "push") == 0 ||
		strcmp(opcode, "pall") == 0 ||
		strcmp(opcode, "pint") == 0 ||
		strcmp(opcode, "pop") == 0 ||
		strcmp(opcode, "swap") == 0 ||
		strcmp(opcode, "add") == 0 ||
		strcmp(opcode, "sub") == 0 ||
		strcmp(opcode, "mul") == 0 ||
		strcmp(opcode, "div") == 0 ||
		strcmp(opcode, "mod") == 0 ||
		strcmp(opcode, "nop") == 0 ||
		strcmp(opcode, "pchar") == 0 ||
		strcmp(opcode, "pstr") == 0 ||
		strcmp(opcode, "rotl") == 0 ||
		strcmp(opcode, "rotr") == 0)
		return (0);

	return (1);
}
