#include "shell.h"
/**
 * chech_path - checks for a path
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
		while ( (ent = readdir(dp)))
		{
			if ((ent->d_name) == p)
				return (combine(P));
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

	new_path = malloc((strlen(s) + 1 + strlen(p)));
	
	strcpy(new_path, p);
	strcat(new_path, s);
	return (new_path);
}	
