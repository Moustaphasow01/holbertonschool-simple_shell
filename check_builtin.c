#include "main.h"

/**
 *check_builtin - function for checking
 *if a builtin exist
 *@command: command entered by user
 *Return: NULL if no builtin, or the right function if builtin is found
 */

int (*check_builtin(char *command))(char *cmd, char **args, char **env)
{
	int i;
	built_in k[] = {
		{"exit", new_exit},
		{NULL, NULL},
	};

	for (i = 0; k[i].command != NULL; i++)
	{
		if (strcmp(command, k[i].command) == 0)
			return (k[i].f);
	}
	return (NULL);
}