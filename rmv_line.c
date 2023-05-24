#include "shell.h"

/**
 * remove_new_line - A function that removes a new line character from string
 * @str: The string
 * Return: The string without a new line character
 */
char *remove_new_line(char *str)
{
	int x = 0;

	while (str[x])
	{
		if (str[x] == '\n')
			str[x] = '\0';
		x++;
	}

	return (str);
}
