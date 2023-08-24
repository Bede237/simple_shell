#include "shell.h"
/**
 * print_env - prints current env
 * @command: command
 * @envp: envp
 * @argv: commandline args
 *
 * Return: 0(success) otherwise(-1)
 */
int print_envp(char **command, char **envp, char **argv)
{
	int i = 0;

	(void)envp;
	if (command == NULL)
	{
		perror(argv[0]);
		return (-1);
	}
	while (environ[i])
	{
		put_s(environ[i]);
		put_char('\n');
		i++;
	}
	return (0);
}
