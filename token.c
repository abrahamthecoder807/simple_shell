#include "shell.h"

/**
 * tokenize - A function that extracts tokens from string
 * @str: The string to tokenize
 * @delim: The delimimiter of tokenization
 * @len: Tokens
 * Return: An array of tokens of the string
 */
char **tokenize(char *str, char *delim, int len)
{
	char **tokens = NULL, *token = NULL, *temp = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * (len + 1));
	if (!tokens)
		return (NULL);

	str = remove_new_line(str);
	temp = _strdup(str);
	token = strtok(temp, delim);

	while (token)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	free(temp);
	return (tokens);
}
