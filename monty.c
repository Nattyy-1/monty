#include "monty.h"

/**
 * main - a simple monty bytecode interpreter
 * @argc: the number of arguments passed to main
 * @argv: the list of arguments passed to the interpreter
 *
 * Return: 0 on success, otherwise exits with the proper error code
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char line[256];
	int err_no;
	unsigned int line_number = 0;
	instruction_t current_instruction;
	stack_t *stack_head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), fp) != NULL)
	{
		line_number++;
		err_no = parse_line(line, &current_instruction);
		if (err_no == 0)
			current_instruction.f(&stack_head, line_number);
		else if (err_no == 2)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, current_instruction.opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(fp);
	return (0);
}
