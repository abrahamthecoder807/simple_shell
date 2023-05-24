#include "shell.h"

/**
 * _getenv - A function that gets the value of an environment variable
 * @varname: The name of the variable to find in the system environment
 * Return: The value of the environment variable
 */
char *_getenv(const char *varname)
{
	int index = 0;
	char *envVarValue = NULL;

	while (environ[index])
	{
		if (_strncmp(varname, environ[index], _strlen(varname)) == 0)
		{
			envVarValue = _strdup(environ[index]);
			while (*envVarValue != '=')
				envVarValue++;

			++envVarValue;
			return (envVarValue);
		}
		index++;
	}

	return (NULL);
}
