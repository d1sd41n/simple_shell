#include "holberton.h"

/**
 * execute - Function for run commands.
 * @p: entri command line.
 * @line: char pointer.
 * @text: pointer name command.
 * @pname: pointer head.
 * Return: final .status
 */
void execute(char *p, char *line[], char *text, char *pname)
{
	if (execve(p, line, NULL) == -1)
	{
		perror(pname);
		free(text);
		exit(1);
	}
}


/**
 * runc - Function for run commands.
 * @line: entri command line.
 * @text: char pointer.
 * @pname: pointer name command.
 * @head: pointer head.
 * @i: pointer head.
 * Return: final .status
 */
void runc(char *line[], char *text, char *pname, list_t *head, unsigned int i)
{
	pid_t PID;
	int status, m;
	struct stat st;
	char *p, *res = NULL;

	PID = fork();
	if (PID == 0)
	{
		if (stat(line[0], &st) != 0)
		{
			for (m = 1; head->next != NULL; m++)
			{
				p = _strcatgoodizer(head->str, line[0], res);
				if (stat(p, &st) == 0)
					execute(p, line, text, pname);
				head = head->next;
			}
			if (i < 4294967295)
			{
				write(STDOUT_FILENO, pname, _strlen(pname));
				write(STDOUT_FILENO, ": ", _strlen(": "));
				print_int(&i);
				write(STDOUT_FILENO, ": ", _strlen(": "));
				write(STDOUT_FILENO, line[0], _strlen(line[0]));
				write(STDOUT_FILENO, ": ", _strlen(": "));
				write(STDOUT_FILENO, "not found", _strlen("not found"));
				_putchar('\n');
				exit(1);
			}
		}
		execute(line[0], line, text, pname);
	}
	else if (PID < 0)
		perror("fork error");
	else
	{
		if (wait(&status) == -1)
			perror("wait error");
	}
}

/**
 * main - main function of shell.
 * @ac: counter arguments.
 * @av: arguments pointer.
 * Return: final .status.
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *line[1024], *token, *text = NULL;
	size_t cont, narg;
	list_t *head = NULL;
	unsigned int i = 0;

	head = cPath(head);
	while (1)
	{
		i++;
		if (isatty(fileno(stdin)))
			write(STDOUT_FILENO, "$> ", _strlen("$> "));
		if (getline(&text, &narg, stdin) == -1)
			break;
		token = strtok(text, " \t\n\r");
		for (cont = 0; cont < 1024 && token != NULL; cont++)
		{
			line[cont] = token;
			token = strtok(NULL, " \t\n\r");
		}
		line[cont] = NULL;
		if (!line[0])
			continue;
		if (_strcmp(line[0], "exit") == 0)
			break;
		if (_strcmp(line[0], "env") == 0)
		{
			_printenv();
			continue;
		}

		runc(line, text, av[0], head, i);
	}
	free(text);
	free_list(head);
	head = NULL;
	exit(0);
}
