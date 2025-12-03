#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack_head: head of the stack
 * @line_number: the line number of the current instruction
 */
void rotr(stack_t **stack_head, unsigned int line_number)
{
	stack_t *temp_head;

	(void)line_number;
	if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
		return;

	temp_head = *stack_head;

	while (temp_head->next != NULL)
		temp_head = temp_head->next;

	temp_head->prev->next = NULL;
	temp_head->next = *stack_head;
	temp_head->prev = NULL;

	(*stack_head)->prev = temp_head;
	*stack_head = temp_head;
}
