#include "monty.h"

/**
 * sub - Monty op_code that subtracts the top element of the stack from the
 *	 second element and stores it on the second element, removing the top at
 *	 the end
 * @stack_head: head of the stack
 * @line_number: the line number of the current instruction
 */
void sub(stack_t **stack_head, unsigned int line_number)
{
	if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack_head)->next->n = (*stack_head)->next->n - (*stack_head)->n;
	pop(stack_head, line_number);
}
