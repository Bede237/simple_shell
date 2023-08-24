#include "shell.h"
/**
 * reallocate - reallocates memory
 * @p: pointer
 * @new: new size of pointer
 * Return: new pointer
 */

void *reallocate(void *p, unsigned int new)
{
	char *pointer;
	unsigned int old = sizeof(p);

	if (!p)
		return (malloc(new));
	if (!new)
		return (free(p), NULL);
	if (new == old)
		return (p);

	pointer = malloc(new);
	if (!pointer)
		return (NULL);

	old = old < new ? old : new;
	while (old--)
		pointer[old] = ((char *)p)[old];
	free(p);
	return (pointer);
}
