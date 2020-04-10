#include "holberton.h"
#include <stdio.h>
/**
 * _strcmp - Write a function that compares two strings.
 * @s1: string to compare 1.
 * @s2: string to compare 2.
 * Return: Always 0.
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
			return (0);
	}
	return (s1[i] - s2[i]);
}
