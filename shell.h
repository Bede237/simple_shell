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
char *str_cat(char *string1, char *string2);
int str_cmp(char *s, char *p);
int str_len(char *string);
char *str_cpy(char *string1, char *string2);
ssize_t get_line(char **string, size_t *n, FILE *stream);
int put_s(char *p);
int put_char(char s);
void print_error(char *string, char *p, int n);
char *_strtok(char *s, char *d);

#endif
