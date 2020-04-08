#include "holberton.h"

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

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *temp = *head;
	list_t *node;
	int i;

	node = malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);

	node->next = NULL;
	node->str = strdup(str);
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