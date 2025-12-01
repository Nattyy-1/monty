#include "monty.h"

/**
 * add - monty op_code that adds the top two elements of the stack and stores
 *	 the result in the second element, finally deleting the top
 * @stack_head: the head of the stack
 * @line_number: the line number of the current instruction
 */
void add(stack_t **stack_head, unsigned int line_number)
{
	if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack_head)->next->n = (*stack_head)->n + (*stack_head)->next->n;
	pop(stack_head, line_number);
}
