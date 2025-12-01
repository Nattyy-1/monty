#include "monty.h"

/**
 * parse_line - parses a line of Monty bytecode and sets current instruction
 * @line: the line holding the bytecode
 * @current_instruction: pointer to the instruction to be executed
 *
 * Return: 0 if successful, 1 if opcode is invalid, 2 if push argument invalid
 *	   , 3 if empty line or a comment
 */
int parse_line(char *line, instruction_t *current_instruction)
{
	char *opcode;
	char *arg;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return (3);

	if (check_op_code(opcode) == 1)
		return (1);

	current_instruction->opcode = opcode;
	current_instruction->f = get_function(opcode);

	if (requires_argument(opcode))
	{
		arg = strtok(NULL, " \t\n");
		if (arg == NULL || !is_number(arg))
			return (2);

		push_value = atoi(arg);
	}

	return (0);
}
