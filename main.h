#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__

typedef struct built_in
{
	char *command;
	int (*f)(char *cmd, char **args, char **env);
} built_in;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


#define IN 1
#define OUT 0

/** Functions Created Before */
char *_strcpy(char *dest, const char *src);
char *_strcon(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int _strlen(char *s);

/** Functions Created for this Project */
size_t wordcount(char *str);
char **get_args(char *buffer);
int main(int argc, char **argv, char **env);
int test_args(char **env, char *buffer, char **args);
void free_args(char **args);
char *pathfinder(char *cmd, char *PATH);
int new_exit(char *cmd, char **args, char **env);
int executor(char *buff, char **env, int line);
int exec_path(char **args, char **env, int line);
int (*check_builtin(char *command))(char *cmd, char **args, char **env);
int print_env(char *cmd, char **args, char **env);
#endif /* SIMPLE_SHELL */
