#include "holberton.h"

/**
 * _strlen - writes nudscfdsmbers
 * @s: pointer
 * Return: none
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (1)
	{
		if (s[i] == '\0')
			break;
		i += 1;
	}
	return (i);
}
