#include "holberton.h"

/**
 * _strncmp - Function compare 2 string.
 * @s1: String 1.
 * @s2: String 2.
 * @bytes: length string.
 * Return: Always dest.
 */

int _strncmp(char *s1, char *s2, size_t bytes)
{
	unsigned int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; s1[i] && s2[i] && s2[i] == s1[i] && i < bytes - 1; i++)
		;
	return (s2[i] - s1[i]);
}
