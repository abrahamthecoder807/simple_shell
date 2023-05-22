#include "shell.h"

/**
 * countWords - A function that counts the number of words in the string
 * @inputString: The string containing the words
 * Return: Number of words in string
 */
int countWords(char *inputString)
{
	int index = 0, wordCount = 0, state = 0;

	while (inputString[index])
	{
		if (inputString[index] == ' '
				|| inputString[index] == '\n'
				|| inputString[index] == '\t')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			wordCount++;
		}

		index++;
	}

	return (wordCount);
}
/**
 * countDelimiters - A function that counts the
 * occurrences of delimiters in a string
 * @inputString: The string to search for delimiters
 * @delimiters: The string containing delimiters to find in the input string
 * Return: The number of delimiter in the string
 */
int countDelimiters(char *inputString, char *delimiters)
{
	int i = 0, j = 0, delimiterCount = 0;

	while (delimiters[i])
	{

		j = 0;
		while (inputString[j])
		{
			if (inputString[j] == delimiters[i])
			{
				delimiterCount++;
				break;
			}
			j++;
		}
		i++;
	}

	return (delimiterCount);
}
