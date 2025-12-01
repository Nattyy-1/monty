#include "monty.h"

/**
 * push - Monty op_code that pushes a given integer on to a stack
 * @stack_head: the head of the stack
 * @line_number: the line number of the current instruction
 */
void push(stack_t **stack_head, unsigned int line_number)
{
	stack_t *node = malloc(sizeof(stack_t));

	(void)line_number;

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = push_value;
	node->prev = NULL;
	node->next = NULL;

	if (*stack_head == NULL)
	{
		*stack_head = node;
		return;
	}

	(*stack_head)->prev = node;
	node->next = *stack_head;
	*stack_head = node;
}
