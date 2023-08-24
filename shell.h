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

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

extern char **environ;
char **tokenize(char *p);
char *combine(char *s);
char *check_path(char *p);
char *str_cat(char *string1, char *string2);
int str_cmp(char *s, char *p);
int str_len(char *string);
char *str_cpy(char *string1, char *string2);
ssize_t _getline(char **string, size_t *n, FILE *stream);
int exit_(char **argv, char **command, int count);
void print_exit_errors(char *pt, int count, char *num);
int a_to_i(char *p);
int print_envp(char **command, char **envp, char **argv);
int handle_commands(char **args, int count, char **argv, char **envp);
int handle_inbuilt(char **args, int count, char **argv, char **envp);
int put_s(char *p);
int put_char(char s);
void print_error(char *string, char *p, int n);
char *_strtok(char *s, char *d);

#endif
