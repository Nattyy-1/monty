#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack, followed by
 *	  a newline
 * @stack_head: head of the stack
 * @line_number: the line number of the current instruction
 */
void pstr(stack_t **stack_head, unsigned int line_number)
{
	stack_t *head;

	(void) line_number;

	if (stack_head == NULL || *stack_head == NULL)
	{
		putchar('\n');
		return;
	}

	head = *stack_head;

	while (head != NULL)
	{
		if (head->n <= 0 || head->n > 127)
			break;

		putchar(head->n);
		head = head->next;
	}

	putchar('\n');
}
