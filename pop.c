#include "monty.h"

/**
 * pop - Monty op code that removes the top element of the stack
 * @stack_head: head of the stack
 * @line_number: the line numberof the current instruction
 */
void pop(stack_t **stack_head, unsigned int line_number)
{
	stack_t *temp;

	if (stack_head == NULL || *stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack_head;

	if ((*stack_head)->next != NULL)
		(*stack_head)->next->prev = NULL;

	*stack_head = (*stack_head)->next;
	free(temp);
}
