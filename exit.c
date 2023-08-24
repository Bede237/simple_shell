#include "shell.h"
/**
 * _exit - exits shell
 * @argv: comandline argument
 * @command: command
 * @count: count
 *
 * Return: 0(success)
 */
int exit_(char **argv, char **command, int count)
{
	int status;
	pid_t bede;

	if (argv[1] == NULL || str_cmp(argv[1], "0"))
	{
		free(argv);
		free(command);
		exit(0);
	}
	status = a_to_i(argv[1]);
	if (status <= 0)
	{
		bede = fork();
		if (bede == 0)
		{
			print_exit_errors(argv[0], count, command[1]);
			free(argv);
			free(command);
			exit(2);
		}
		else
		{
			wait(NULL);
			return (0);
		}
	}
	free(argv);
	free(command);
	exit(status);
}
/**
 * print_exit_errors - prints message
 * @pt: shell name
 * @count: count
 * @num: status
 */
void print_exit_errors(char *pt, int count, char *num)
{
	put_s(pt);
	put_s(": ");
	put_char(count + '0');
	put_s(": exit: Illegal number: ");
	put_s(num);
	put_char('\n');
}
