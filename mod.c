#include "monty.h"

/**
 * mod - computes the rest of the division between the top and second top of stack
 * @stack_head: head of the stack
 * @line_number: the line number of the current instruction
 */
void mod(stack_t **stack_head, unsigned int line_number)
{
	if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack_head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack_head)->next->n = (*stack_head)->next->n % (*stack_head)->n;
	pop(stack_head, line_number);
}
