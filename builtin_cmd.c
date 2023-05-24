#include "shell.h"

/**
 * execute_builtin_commands - Executes a built-in command
 * @tokens: parameter tokens`
 * @inputLine: builtin commands to check for
 * Return: 1 if it is a built-in command, or 0 if not
 */
int execute_builtin_commands(char **tokens, char *inputLine)
{
	int index = 0;
	char *builtinCommands[] = { "exit", "cd", "help", "env", NULL };

	while (builtinCommands[index])
	{
		if (_strcmp(tokens[0], builtinCommands[index]) == 0)
		{
			if (index == 0)
			{
				handle_exit(tokens, inputLine);
				return (1);
			}
			else if (index == 1)
			{
				chdir(tokens[1]);
				return (1);
			}
			else if (index == 2)
			{
				print_enviro();
				return (1);
			}
		}
		index++;
	}
	return (0);
}
