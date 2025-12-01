#include "monty.h"

/**
 * mul - Monty op_code that multiplies the second top element of the stack with
 *	 the first
 * @stack_head: head of the stack
 * @line_number: the line number of the current instruction
 */
void mul(stack_t **stack_head, unsigned int line_number)
{
	if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack_head)->next->n = (*stack_head)->next->n * (*stack_head)->n;
	pop(stack_head, line_number);
}
