#include "monty.h"

/**
 * rotl - Monty op_code that rotates the stack to the top
 * @stack_head: head of the stack
 * @line_number: the line number of the current instruction
 */
void rotl(stack_t **stack_head, unsigned int line_number)
{
	stack_t *temp_ptr;
	stack_t *temp_head;

	(void)line_number;
	if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
		return;

	temp_ptr = *stack_head;
	*stack_head = (*stack_head)->next;
	(*stack_head)->prev = NULL;

	temp_head = *stack_head;
	while (temp_head->next != NULL)
		temp_head = temp_head->next;

	temp_head->next = temp_ptr;
	temp_ptr->prev = temp_head;
	temp_ptr->next = NULL;
}
