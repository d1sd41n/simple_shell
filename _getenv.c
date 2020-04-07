#include "holberton.h"


char *_getenv(char *varenv)
{
	int i = 0, j, size;
	char *aux;

	if (varenv == NULL)
		return (NULL);
    while(environ[i] != NULL)
	{
        size = 0;
        while(environ[i][size] != '=')
            size++;
		size++;
		aux = malloc(size);
		size--;
		_memcpy(aux, environ[i], size);
		if (_strncmp(varenv, aux, size) == 0)
		{
			free(aux);
            j = 0;
            while(environ[i][j])
			{
				if (environ[i][j] == '=')
				{
					aux = &environ[i][j + 1];
					break;
				}
                j++;
			}
			return (aux);
		}
		free(aux);
		aux = NULL;
        i++;
	}
	return (NULL);
}