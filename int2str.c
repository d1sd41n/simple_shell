#include "holberton.h"

char *int2str(unsigned int i, char Array[])
{
    char numbers[] = "0123456789", *pos = Array;

    int num = i;
    do {
        pos++;
        num /= 10;
    } while (num > 0);

    *pos = '\0';

    do {
        pos--;
        *pos = numbers[i % 10];
        i /= 10;
    } while (i > 0);

    return Array;
}

void print_int(unsigned int *i)
{
    char st[11], *p;
    p = int2str(*i, st);

    write(STDOUT_FILENO, p, _strlen(p));
}