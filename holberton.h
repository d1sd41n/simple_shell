#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

extern char **environ;

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

int _putchar(char c);
char *_memcpy(char *dest, char *src, unsigned int n);
int _strncmp(char *s1, char *s2, size_t bytes);
int _strlen(char *s);
char *_getenv(char *varenv);
size_t print_list(const list_t *h);
char *_strdup(char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

#endif
