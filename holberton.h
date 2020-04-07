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

int _putchar(char c);
char *_memcpy(char *dest, char *src, unsigned int n);
int _strncmp(char *s1, char *s2, size_t bytes);
int _strlen(char *s);
char *_getenv(char *varenv);

#endif
