#include "shell.h"
/**
 * print_error - prints error on screen
 * @s: command name
 * @p: name of file
 * @n: count
 */
void print_error(char *s, char *p, int n)
{
	char *pt = "not found";

	put_s(s);
	put_char(':');
	put_char(' ');
	put_char((char)(n + '0'));
	put_char(':');
	put_char(' ');
	put_s(p);
	put_char(':');
	put_char(' ');
	put_s(pt);
	put_char('\n');
}
/**
 * put_s - write a string to screen
 * @s: ppointer to string
 * 
 * Returns: count of string
 */
int put_s(char *s)
{
	int m = 0;

	while (s[m] != '\0')
	{
		put_char(s[m]);
		m++;
	}
	return (m);
}
/**
 * put_char - puts char to screen
 * @s: characted to be printed
 *
 * Return: number of char
 */
int put_char(char s)
{
	return(write(1, &s, 1));
}
