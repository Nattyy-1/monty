#include "monty.h"

/**
 * pchar - prints the char at the top of the stack followed by a newline
 * @stack_head: head of the stack
 * @line_number: the line number of the current instruction
 */
void pchar(stack_t **stack_head, unsigned int line_number)
{
	int ascii_value;

	if (stack_head == NULL || *stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii_value = (*stack_head)->n;

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(ascii_value);
}
