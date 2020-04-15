#include "holberton.h"

/**
 * print_error - print error message.
 * @pname: program name.
 * @command: command first part.
 * @i: conter.
 * Return: void.
 */

void print_error(char *pname, char *command, unsigned int i)
{
	write(STDERR_FILENO, pname, _strlen(pname));
	write(STDERR_FILENO, ": ", _strlen(": "));
	print_int(&i);
	write(STDERR_FILENO, ": ", _strlen(": "));
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": ", _strlen(": "));
	write(STDERR_FILENO, "not found", _strlen("not found"));
	write(STDERR_FILENO, "\n", _strlen("\n"));
}

/**
 * print_error_p - print error message.
 * @pname: program name.
 * @command: command first part.
 * @i: conter.
 * Return: void.
 */
void print_error_p(char *pname, char *command, unsigned int i)
{
	write(STDERR_FILENO, pname, _strlen(pname));
	write(STDERR_FILENO, ": ", _strlen(": "));
	print_int(&i);
	write(STDERR_FILENO, ": ", _strlen(": "));
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": ", _strlen(": "));
	write(STDERR_FILENO, "Permission denied", _strlen("Permission denied"));
	write(STDERR_FILENO, "\n", _strlen("\n"));
}
