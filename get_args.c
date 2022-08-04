#include "main.h"

/**
 * get_args - Fct that gets token
 *
 * @buffer: memory used to retrieve input
 * Return: token
 */

char **get_args(char *buffer)
{
	char **args = NULL, *arg = NULL;
	int i = 0;

	args = malloc(sizeof(char *) * (wordcount(buffer) + 1));
	arg = strtok(buffer, " ");

	while (arg != NULL)
	{
		args[i] = strdup(arg);
		arg = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	return (args);
}