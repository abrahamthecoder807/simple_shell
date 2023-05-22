#include "shell.h"

/**
 * printEnvironment - A function that prints the environment variables
 * Return: Nothing.
 */
void printEnvironment(void)
{
	int index = 0;
	int charIndex = 0;

	while (environ[index])
	{
		charIndex = 0;
		while (environ[index][charIndex])
		{
			_putchar(environ[index][charIndex]);
			charIndex++;
		}

		if (charIndex != 0)
			_putchar('\n');
		index++;
	}
}
