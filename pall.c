#include "monty.h"

/**
 * pall - Monty op_code that prints all the elements on the stack
 * @stack_head: head of the stack
 * @line_number: the line number of the current instruction
 */
void pall(stack_t **stack_head, unsigned int line_number)
{
	stack_t *head = *stack_head;

	(void)line_number;

	if (stack_head == NULL || *stack_head == NULL)
		return;

	while(head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
