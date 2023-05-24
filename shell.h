#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char ** environ;

int execute_builtin_commands(char **tokens, char *inputLine);
void handle_exit(char **command, char *input_line);
void print_enviro(void);
char *_getenv(const char *varname);
int countDelimiters(char *inputString, char *delimiters);
int count_Words(char *inputString);
char *findCommand(char *cmdname);
int exec(char *cmdname, char **flags);
char *concat_path(char *pathname, char *progname);
void frees_mem_env(char *env_path);
void frees_tokens(char **tokns);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *_strdup(char *str);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t len);
int _putchar(char c);
void *_realloc(void *ptr, unsigned int init_size, unsigned int new_size);
void _puts(char *str);
char **tokenize(char *str, char *delim, int len);
void signal_handler(int sig_id);
char *remove_new_line(char *str);

#endif
