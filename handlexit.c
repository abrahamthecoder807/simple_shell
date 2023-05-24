#include "shell.h"

/**
 * handle_exit - A function that handles the exit command in a shell
 * @command: Command and arguments array
 * @input_line: Input line
 * Return: Nothing.
 */
void handle_exit(char **command, char *input_line)
{
	int exit_status = 0;

	if (command[1] == NULL || (!_strcmp(command[1], "0")))
	{
		frees_tokens(command);
		free(input_line);
		exit(0);
	}

	exit_status = _atoi(command[1]);

	if (exit_status != 0)
	{
		frees_tokens(command);
		free(input_line);
		exit(exit_status);
	}
	else
	{
		_puts("exit: number not valid: ");
		_puts(command[1]);
		_puts("\n");
		exit(2);
	}
	frees_tokens(command);
	free(input_line);
	exit(EXIT_SUCCESS);
}
