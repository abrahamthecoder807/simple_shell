#include "shell.h"

/**
 * concat_path - A function that concatenates a path name and a program name
 * @progname: name of program to concatenate
 * @pathname: name of path to concatenate
 * Return: Concatenated string
 */
char *concat_path(char *pathname, char *progname)
{
	int progname_len = 0;
	int pathname_len = 0;
	int mem_size = 0;

	progname_len = _strlen(progname);
	pathname_len = _strlen(pathname);
	mem_size = sizeof(char) * (pathname_len + progname_len + 2);
	pathname = _realloc(pathname, (pathname_len + 1), mem_size);
	if (!pathname)
		return (NULL);

	_strcat(pathname, "/");
	_strcat(pathname, progname);

	return (pathname);
}
/**
 * findCommand - A function that verifies a command is in the program
 * @cmdname: The command name to find in the system
 * Return: The path name of the command found or NULL if failed
 */
char *findCommand(char *cmdname)
{
	char *env_path = NULL;
	char **tokens = NULL;
	int i = 0;
	int numDelimiter = 0;
	struct stat sb;

	if (cmdname)
	{
		if (stat(cmdname, &sb) != 0 && cmdname[0] != '/')
		{
			env_path = _getenv("PATH");
			numDelimiter = countDelimiters(env_path, ":") + 1;
			tokens = tokenize(env_path, ":", numDelimiter);

			while (tokens[i])
			{
				tokens[i] = concat_path(tokens[i], cmdname);

				if (stat(tokens[i], &sb) == 0)
				{
					free(cmdname);
					cmdname = _strdup(tokens[i]);
					frees_mem_env(env_path);
					frees_tokens(tokens);
					return (cmdname);
				}

				i++;
			}

			frees_mem_env(env_path);
			frees_tokens(tokens);
		}

		if (stat(cmdname, &sb) == 0)
			return (cmdname);
	}

	free(cmdname);
	return (NULL);
}
/**
 * exec - A function that executes a command
 * @cmdname: The command to execute
 * @flags: the flags or option to the command
 * Return: An integer
 */
int exec(char *cmdname, char **flags)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("fork failed");
		return (-1);
	} else if (child == 0)
	{
		execve(cmdname, flags, environ);
	} else
	{
		do {
			waitpid(child, &status, WUNTRACED);
		} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}

	return (0);
}
