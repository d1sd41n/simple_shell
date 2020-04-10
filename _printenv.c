#include "holberton.h"

/**
 * _printenv - Get the enviroment var content.
 *
 * Return: Void.
 */

void _printenv(void)
{
	int i = 0;


	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", _strlen("\n"));
		i++;
	}
}
