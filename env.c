#include "shell.h"
/**
 * print_envp - prints current env
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
		_put(environ[i]);
		_putchar('\n');
		i++;
	}
	return (0);
}
/**
 * _put - prints the text entered to the console
 * @str: text to be printed
 *
 * Return: void
*/
void _put(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - prints a character
 * @c: character to be printed
 *
 * Return: void
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
