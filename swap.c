#include "monty.h"

/**
 * swap - Monty op_code that swaps the top two elemets of the stack
 * @stack_head: head of the stack
 * @line_number: the current line number of the instruction
 */
void swap(stack_t **stack_head, unsigned int line_number)
{
	int temp;

	if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack_head)->n;
	(*stack_head)->n = (*stack_head)->next->n;
	(*stack_head)->next->n = temp;
}
