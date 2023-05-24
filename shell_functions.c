#include "shell.h"
/**
 * _strcmp -A function that checks andsl compares two strings
 * @s1: The first string
 * @s2: The second string
 * Return: An integer
 */
int _strcmp(char *s1, char *s2)
{
	int stlen_s1 = 0, stlen_s2 = 0, cur_pos = 0, diff = 0, lim = 0;

	stlen_s1 = _strlen(s1);
	stlen_s2 = _strlen(s2);

	if (stlen_s1 <= stlen_s2)
		lim = stlen_s1;
	else
		lim = stlen_s2;

	while (cur_pos <= lim)
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
 * _atoi - A function that converts a string to an integer.
 * @p: The pointer to convert
 * Return: An integer
 */
int _atoi(char *p)
{
	int cur_pos = 0, isi = 0, sign = 1;
	unsigned int nw_int = 0;

	while (p[cur_pos])
	{
		if (p[cur_pos] == '-')
			sign *= -1;

		while (p[cur_pos] >= '0' && p[cur_pos] <= '9')
		{
			isi = 1;
			nw_int = (nw_int * 10) + (p[cur_pos] - '0');
			cur_pos++;
		}

		if (isi == 1)
			break;

		cur_pos++;
	}

	nw_int *= sign;
	return (nw_int);
}
/**
 * _strdup - A function that duplicate a string
 * @str: the string to duplicate
 * Return: the string duplicated
 */
char *_strdup(char *str)
{
	int x = 0, len = 1;
	char *dup_str;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	dup_str = malloc((sizeof(char) * len) + 1);
	if (dup_str == NULL)
		return (NULL);

	while (x < len)
	{
		dup_str[x] = str[x];
		x++;
	}

	dup_str[x] = '\0';
	return (dup_str);
}
/**
 * _strlen - A function that counts the length of a string
 * @s: The string to counts
 * Return: The length of a string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}
