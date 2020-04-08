#include "holberton.h"
/**
 * main - main function of shell.
 * Return: final .status
 */
int main(void)
{
	pid_t PID;
	char *line[1024], *token, *text = NULL;
	size_t cont, narg;
	int status;

	while (1)
	{
		printf("$> ");
		if (getline(&text, &narg, stdin) == -1)
			break;
		token = strtok(text, " \t\n\r");
		for (cont = 0; cont < 1024 && token != NULL; cont++)
		{
			line[cont] = token;
			token = strtok(NULL, " \t\n\r");
		}
		line[cont] = NULL;
		PID = fork();
		if (PID == 0)
		{
			if (execve(line[0], line, NULL) == -1)
				perror("Error:");
		}
		wait(&status);
	}
	free(text);
	exit(status);
}
