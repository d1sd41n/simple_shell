#include "holberton.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

typedef struct list_s
{
        char *str;
        unsigned int len;
        struct list_s *next;
} list_t;

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

char *_strdup(char *str)
{
        char *copy;
        unsigned int i, m = 0;

        if (str == NULL)
                return (NULL);
        else
        {
                i = 0;
                while (str[i] != '\0')
                        i++;
        }
        i++;
        copy = malloc(sizeof(char) * i);
        if (copy == NULL)
                return (NULL);
        for (m = 0; m < i; m++)
                copy[m] = str[m];
        return (copy);
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

int main(void)
{
        list_t *head;
        char *path;
        char *token;

        head = NULL;
        path = getenv("PATH");
        token = strtok(path, ":");
        while (token != NULL)
        {
                add_node_end(&head,token);
                token = strtok(NULL, ":");
        }
        print_list(head);
        free_list(head);
        head = NULL;
        return (0);

}
