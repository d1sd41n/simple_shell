#include "holberton.h"

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