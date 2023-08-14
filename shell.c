#include "shell.h"
/**
 * main - Entry point
 *
 * Return: 0 (success)
 */
int main(void)
{
	int i = 0, m = 0;
	size_t len = 0;
	ssize_t n;
	char *command = NULL,  **argv;
	pid_t pd;

	argv = malloc(sizeof(char *));
	while (1)
	{
		if (isatty(STDOUT_FILENO))
			printf("#cisfun$ ");
		n = getline(&command, &len, stdin);
		if (n == -1)
			break;
		while (command[i] != '\0')
		{
			i = i + 1;
		}
		if (command[(i - 1)] == '\n')
			command[(i - 1)] = '\0';
		argv = tokenize(command);
		pd = fork();
		if (pd < 0)
		{
			perror("fork failed");
		}
		else if (pd == 0)
		{
			m = execve(argv[0], argv, environ);
			if (m == -1)
				perror("./shell: No such file or directory");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	free(command);
	return (0);
}
/**
 * tokenize - to tokenize
 * @p: pointer to string
 *
 * Return: pointer to tokenized string
 */
char **tokenize(char *p)
{
	char **argv, *token;
	int m = 0;
	int n = 0;

	argv = malloc(sizeof(char *));

	token = strtok(p, " ");

	while (token != NULL)
	{
		while (token[n] != '\0')
		{
			if (token[n] == '\n')
				token[n] = '\0';
			n++;
		}
		n = 0;
		argv[m] = malloc(sizeof(char *) * strlen(token));
		strcpy(argv[m], token);
		m++;
		token = strtok(NULL, " ");
	}
	argv[m] = NULL;
	return (argv);
}
