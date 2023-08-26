#include "shell.h"
/**
 * str_len - lenght of string
 * @string: string
 *
 * Return: length of string
 */
int str_len(char *string)
{
	int i = 0;
	int count = 0;

	if (string == NULL)
		return (0);
	while (string[i] != '\0')
	{
		count = count + 1;
		i++;
	}
	return (count);
}
/**
 * str_cpy - copies string
 * @string1: destination
 * @string2: string to be copied
 *
 * Return: pointer to string
 */
char *str_cpy(char *string1, char *string2)
{
	int i = 0;

	while (string2[i] != '\0')
	{
		string1[i] = string2[i];
		i++;
	}
	string1[i] = '\0';
	return (string1);
}
/**
 * str_cat - concatenates strings
 * @string1: destination
 * @string2: string to be added
 *
 * Return: pointer to string
 */
char *str_cat(char *string1, char *string2)
{
	int i = 0, j = 0;

	while (string1[i] != '\0')
	{
		i++;
	}

	while (string2[j] != '\0')
	{
		string1[i] = string2[j];
		i++;
		j++;
	}
	string1[i] = '\0';
	return (string1);
}
/**
 * str_cmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0(strings match)
 */
int str_cmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	if (s2[i] != '\0')
		return (-1);
	return (0);
}
