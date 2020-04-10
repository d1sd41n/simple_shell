#include "holberton.h"

/**
 * _memcpy - memory copy of estring
 *
 * @dest: new string.
 * @src: sourse string.
 * @n: number of characters to copy.
 *
 * Return: string dest
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
