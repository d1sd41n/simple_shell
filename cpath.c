#include "holberton.h"
/**
 * cPath - path possible of enviroment.
 * @head: ponter head
 *
 * Return: Head of pointer
*/

list_t *cPath(list_t *head)
{
	char *path;
	char *token;

	path = _getenv("PATH");
	token = strtok(path, ":");
	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}
