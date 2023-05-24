#include "shell.h"

/**
 * frees_mem_env - A function that frees the memory allocated
 * to an environment variable
 * @env_path: The environment variable to free
 * Return: Nothing
 */
void frees_mem_env(char *env_path)
{
	int i;

	for (i = 4; i >= 0; i--)
		env_path--;

	free(env_path);
}

/**
 * frees_tokens - A function that frees the memory allocated
 * to an array of tokens
 * @tokns: The array of token to free
 * Return: Nothing
 */
void frees_tokens(char **tokns)
{
	char **temp = tokns;

	if (tokns)
	{
		while (*tokns)
			free(*tokns++);

		free(temp);
	}
}
