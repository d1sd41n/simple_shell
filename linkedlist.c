#include "holberton.h"
/**
 * print_list - Print each node content.
 * @h: head of linked list.
 * Return: m number of nodes.
 */

size_t print_list(const list_t *h)
{
	int m;

	if (h == NULL)
		return (0);
	for (m = 1; h->next != NULL; m++)
	{
		if (h->str == NULL)
			printf("[%u] %s\n", h->len, "(nil)");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
	}
	printf("[%u] %s\n", h->len, h->str);
	return (m);
}

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
