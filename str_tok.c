#include "shell.h"
/**
 * _strtok - tokenizes a string
 * @s: string to tokenize
 * @d: delimiter
 *
 * Return: pointer to string
 */
char *_strtok(char *s, char *d)
{
	static char *last_token;
	static char *token;
	int i = 0, j = 0;

	if (s != NULL)
	{
		last_token = s;
	}
	else if (last_token == NULL)
	{
		return (NULL);
	}
	token = last_token;
	while (last_token[i] != '\0')
	{
		while (d[j] != '\0')
		{
			if (last_token[i] == d[j])
			{
				last_token[i] = '\0';
				i++;
				return (token);
			}
			j++;
		}
		i++;
	}
	last_token = NULL;
	if (str_cmp(token, ""))
	{
		return (_strtok(NULL, " "));
	}
	return (token);
}
