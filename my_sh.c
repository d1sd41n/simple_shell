#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
	pid_t PID;
	char *line[1024];
	char *token;
	char *text = NULL;
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
			if (execve(line[0], line, envp))
			{
				exit(EXIT_FAILURE);
			}
		}
		if (PID > 0)
			wait(&status);
	}
	putchar('\n');
	free(text);
	exit(status);
}
