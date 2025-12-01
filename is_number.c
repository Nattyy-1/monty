#include "monty.h"

/**
 * is_number - checks if a given string is a number or not
 * @argument: the string being checked
 *
 * Return: 1 if the string is a valid number, else 0
 */
int is_number(char *argument)
{
	int i = 0;

	if (argument == NULL || argument[0] == '\0')
		return (0);

	if (argument[0] == '-')
		i = 1;

	while (argument[i] != '\0')
	{
		if (isdigit(argument[i]) == 0)
			return (0);

		i++;
	}

	return (1);
}

