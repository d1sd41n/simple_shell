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
#include <errno.h>

extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string path.
 * @len: length of path.
 * @next: next node path.
 *
 * Description: singly linked list node structure
 * for simple shell project.
 */

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
list_t *add_node_end(list_t **head, char *str);
void free_list(list_t *head);
char *_strcatgoodizer(char *dest, char *src, char *res);
list_t *cPath(list_t *head);
int _strcmp(char *s1, char *s2);
void _printenv(void);
char *int2str(unsigned int i, char Array[]);
void print_int(unsigned int *i);
void print_error(char *pname, char *command, unsigned int i);
int runc(char *line[], char *text, char *pm, list_t *head, unsigned int i);
void print_error_p(char *pname, char *command, unsigned int i);

#endif
