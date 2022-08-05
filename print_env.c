#include "shell.h"

/**
 *print_env - prints the current environment
 *@cmd: command inputed by user
 *@args: array of arguments
 *@env: array of strings of the env
 *Return: always 0 (success)
 */

int print_env(char *cmd, char **args, char **env)
{
	unsigned int i = 0;

	(void)cmd;
	(void)args;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}