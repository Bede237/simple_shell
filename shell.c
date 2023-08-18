#include "shell.h"
/**
 * main - Entry point
 *
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	int i = 0, m = 0, count = 0;
	size_t len = 0;
	ssize_t n;
	char *command = NULL,  **args, *new;
	pid_t pd;

	if (argc < 1)
		argv = NULL;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		n = getline(&command, &len, stdin);
		if (n == -1)
			break;
		count = count + 1;
		i = str_len(command);
		if (command[(i - 1)] == '\n')
			command[(i - 1)] = '\0';
		if (str_cmp(command, "exit") == 0)
			exit(EXIT_SUCCESS);
		args = tokenize(command);
		new = check_path(args[0]);
		if (new == NULL)
		{
			print_error(argv[0], args[0], count);
			free(argv);
			free(args);
			continue;
		}
		pd = fork();
		if (pd < 0)
		{
			perror("fork failed");
		}
		else if (pd == 0)
		{
			m = execve(new, args, environ);
			if (m == -1)
				print_error(argv[0], args[0], count);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	free(args);
	free(new);
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
	char **argg, *token, *bede, *s;
	int m = 0;
	int n = 0, i = 0;
	
	s = malloc(sizeof(char) * (str_len(p) + 1));
	str_cpy(s, p);
	bede = strtok(s, " ");
	while(bede != NULL)
	{
		i = i + 1;
		bede = strtok(NULL, " ");
	}	
	argg = malloc(sizeof(char*) * i);
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
		argg[m] = malloc(sizeof(char) * ( strlen(token) + 1));
		str_cpy(argg[m], token);
		m++;
		token = strtok(NULL, " ");
	}
	free(s);
	argg[m] = NULL;
	return (argg);
}
