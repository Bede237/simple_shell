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

	if (s != NULL)
	{
		last_token = s;
	}
	else if (last_token == NULL)
	{
		return (NULL);
	}
	token = last_token;
	while (*last_token != '\0')
	{
		while (*d != '\0')
		{
			if (*last_token == *d)
			{
				*last_token = '\0';
				last_token++;
				return (token);
			}
			d++;
		}
		last_token++;
	}
	last_token = NULL;
	if (str_cmp(token, ""))
	{
		return (_strtok(NULL, " "));
	}
	return (token);
}
