#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
extern char **environ;
char **tokenize(char *p);
char *combine(char *s);
char *check_path(char *p);

#endif
