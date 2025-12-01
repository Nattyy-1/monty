#include "monty.h"

/**
 * nop - Monty op_code that does nothing
 * @stack_head: head of the stack
 * @line_number: the line number of the current instruction
 */
void nop(stack_t **stack_head, unsigned int line_number)
{
	(void)stack_head;
	(void)line_number;
}
