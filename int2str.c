#include "holberton.h"

/**
 * int2str - Convert unsigned int number to array.
 * @i: Int number.
 * @Array: array to insert the string.
 * Return: Array.
 */

char *int2str(unsigned int i, char Array[])
{
	char numbers[] = "0123456789", *pos = Array;
	int num = i;

	do {
		pos++;
		num /= 10;
	} while (num > 0);
	*pos = '\0';
	do {
		pos--;
		*pos = numbers[i % 10];
		i /= 10;
	} while (i > 0);
	return (Array);
}

/**
 * print_int - Print string of numbers.
 * @i: Int number.
 * Return: void.
 */

void print_int(unsigned int *i)
{
	char st[11], *p;

	p = int2str(*i, st);
	write(STDERR_FILENO, p, _strlen(p));
}
