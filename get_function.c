#include "monty.h"

/**
 * get_function - returns a function pointer corresponding to a Monty opcode
 * @opcode: the opcode string to match
 *
 * Return: pointer to the function that executes the opcode, or NULL if invalid
 */
void (*get_function(char *opcode))(stack_t **, unsigned int)
{
	if (strcmp(opcode, "push") == 0)
		return (push);
	else if (strcmp(opcode, "pall") == 0)
		return (pall);
	else if (strcmp(opcode, "pint") == 0)
		return (pint);
	else if (strcmp(opcode, "pop") == 0)
		return (pop);
	else if (strcmp(opcode, "swap") == 0)
		return (swap);
	else if (strcmp(opcode, "add") == 0)
		return (add);
	else if (strcmp(opcode, "sub") == 0)
		return (sub);
	else if (strcmp(opcode, "mul") == 0)
		return (mul);
	else if (strcmp(opcode, "div") == 0)
		return (_div);
	else if (strcmp(opcode, "mod") == 0)
		return (mod);
	else if (strcmp(opcode, "nop") == 0)
		return (nop);
	else if (strcmp(opcode, "pchar") == 0)
		return (pchar);
	else if (strcmp(opcode, "pstr") == 0)
		return (pstr);
	else if (strcmp(opcode, "rotl") == 0)
		return (rotl);
	else if (strcmp(opcode, "rotr") == 0)
		return (rotr);
	else
		return (NULL);
}

