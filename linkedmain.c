#include "holberton.h"

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