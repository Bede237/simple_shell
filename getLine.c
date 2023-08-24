#include "shell.h"
/**
 * _getline - getline function
 * @lineptr: line pointer
 * @n: size of lineptr
 * @fd: File stream to read from
 * Return: size read or -1 (Fail)
 */
ssize_t _getline(char **string, size_t *n, int fd)
{
	static char *buffer;
	static size_t n_chars;
	size_t i = 0;
	char ch;
	static int p = 1;
	ssize_t res;

	if (buffer == NULL)
	{
		n_chars = BUFSIZ;
		buffer = malloc(n_chars);
		if (buffer == NULL)
			return (-1);
	}
	while ((res = read(fd, &ch, 1)) > 0)
	{
		if (ch == '\n')
			break;
		buffer[i++] = ch;
		if (i == (n_chars * p))
		{
			p++;
			n_chars *= p;
			buffer = reallocate(buffer, n_chars);
			if (buffer == NULL)
				return (-1);
		}
		if (buffer == NULL)
			return (-1);
	}

	buffer[i] = '\0';
	*string = buffer;
	*n = n_chars;

	if (res <= 0 && i == 0)
		return (-1);
	return (i);
}
