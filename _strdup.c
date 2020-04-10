#include "holberton.h"
/**
 * _strdup - Duplicates a string using heap memory.
 * @str: String to duplicate.
 * Return: Copy of string.
 */

char *_strdup(char *str)
{
	char *copy;
	unsigned int i, m = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;
	i++;
	copy = malloc(sizeof(char) * i);
	if (copy == NULL)
	{
		free(copy);
		return (NULL);
	}
	if (copy == NULL)
		return (NULL);
	for (m = 0; m < i; m++)
		copy[m] = str[m];
	return (copy);
}
