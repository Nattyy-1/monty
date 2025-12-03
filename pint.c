#include "monty.h"

/**
 * pint - Monty op_code the prints the value at the top of the stack
 * @stack_head: head of the stack
 * @line_number: the line number of the current instruction
 */
void pint(stack_t **stack_head, unsigned int line_number)
{
	(void)line_number;

	if (stack_head == NULL || *stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack_head)->n);
}
