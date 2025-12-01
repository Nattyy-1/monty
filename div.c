#include "monty.h"

/**
 * _div - Monty op_code, divides the second top element by the top element of
 *	  the stack
 * @stack_head: head of the stack
 * @line_number: line number of the current instruction
 */
void _div(stack_t **stack_head, unsigned int line_number)
{
	if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack_head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack_head)->next->n = (*stack_head)->next->n / (*stack_head)->n;
	pop(stack_head, line_number);
}
