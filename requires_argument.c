#include "monty.h"

/**
 * requires_argument - checks if a given Monty op_code requires an argument
 * @op_code: the op_code to check
 *
 * Return: 1 if it requires an argument, otherwise 0
 */
int requires_argument(char *op_code)
{
	if (strcmp(op_code, "push") == 0)
		return (1);

	return (0);
}
