#include "shell.h"
/**
 * check_path - checks for a path
 * @p: pionter to path
 *
 * Return: pointer to path
 */
char *check_path(char *p)
{
	char *pt = "/bin";
	int n = 0;
	struct dirent *ent;
	DIR *dp;

	n = access(p, F_OK);
	if (n == 0)
	{
		return (p);
	}
	else
	{
		dp = opendir(pt);
		if (dp == NULL)
			return (NULL);
		while ((ent = readdir(dp)))
		{
			if (str_cmp((ent->d_name), p) == 0)
			{
				return (combine(p));
			}
		}
		closedir(dp);
	}
	return (NULL);
}
/**
 * combine - create full path
 * @s: pointer to string
 *
 * Return: pointer to new path
 */
char *combine(char *s)
{
	char *p = "/bin/";
	char *new_path;

	new_path = malloc((str_len(s) + 1 + str_len(p)));
	str_cpy(new_path, p);
	str_cat(new_path, s);
	return (new_path);
}
