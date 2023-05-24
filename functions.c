#include "shell.h"
/**
 * _strcat - A function that concatenates two strings
 * @dest: The destination string
 * @src: The source string
 * Return: A pointer to the string
 */
char *_strcat(char *dest, char *src)
{
	int dlen = 0;
	int x = 0;

	while (dest[dlen])
		dlen++;

	for (x = 0; src[x] != '\0'; x++)
	{
		dest[dlen] = src[x];
		dlen++;
	}

	dest[dlen] = '\0';
	return (dest);
}
/**
 * _strncmp - A function that compares the first character of two strings
 * @s1: The first string
 * @s2: The second string
 * @len: The limit bytes of comparison
 * Return: int value
 */
int _strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned int cur_pos = 0;
	int diff = 0;

	while (cur_pos < len)
	{
		if (s1[cur_pos] == s2[cur_pos])
		{
			cur_pos++;
			continue;
		}
		else
		{
			diff = s1[cur_pos] - s2[cur_pos];
			break;
		}

		cur_pos++;
	}

	return (diff);
}

/**
 * _putchar - A function that writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - A function that prints a string
 * @str: The string to print
 * Return: Nothing
 */
void _puts(char *str)
{
	for (; *str; str++)
		_putchar(*str);

	_putchar('\n');
}

/**
 * _realloc - A function that realloctes memory for a pointer
 * @ptr: the previous pointer
 * @init_size: initial size of the pointer
 * @new_size: The new size of the new pointer
 * Return: A new pointer to the memory
 */
void *_realloc(void *ptr, unsigned int init_size, unsigned int new_size)
{
	char *nptr;
	unsigned int i = 0;

	if (new_size == init_size)
		return (ptr);

	if (ptr == NULL)
	{
		nptr = malloc(new_size);

		if (nptr == NULL)
			return (NULL);

		return (nptr);
	}
	else
	{
		if (new_size == 0)
		{
			free(ptr);
			return (NULL);
		}
	}

	nptr = malloc(new_size);

	if (nptr == NULL)
		return (NULL);

	while (i < init_size && i < new_size)
	{
		nptr[i] = ((char *)ptr)[i];
		i++;
	}

	free(ptr);
	return (nptr);
}
