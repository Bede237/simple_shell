#include "shell.h"
/**
 * a_to_i - converts string to num
 * @p: sting num
 *
 * Return: converted int
 */
int a_to_i(char *p)
{
	int sign = 1, i = 0;
	unsigned int top = 0;

	while (!(p[i] <= '9' && p[i] >= '0') && p[i] != '\0')
	{
		if (p[i] == '-')
			sign *= -1;
		i++;
	}
	while (p[i] <= '9' && (p[i] >= '0' && p[i] != '\0'))
	{
		top = (top * 10) + (p[i] - '0');
		i++;
	}
	top = top * sign;
	return (top);
}
