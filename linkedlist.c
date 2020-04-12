#include "holberton.h"

/**
 * add_node_end - Add node to final linked list.
 * @head: haed of linked list.
 * @str: information add to new node.
 * Return: return memory direction node.
 */

list_t *add_node_end(list_t **head, char *str)
{
	list_t *temp = *head;
	list_t *node;
	int i;

	node = malloc(sizeof(list_t));
	if (node == NULL)
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;
	node->str = _strdup(str);
	for (i = 0; str[i] != '\0'; i++)
		;
	node->len = i;
	if (*head == NULL)
		*head = node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
	return (node);
}

/**
 * free_list - free nodes memory used.
 * @head: head of linked list.
 * Return: void.
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
