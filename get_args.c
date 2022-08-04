#include "main.h"
#include "wordcount.c"
/**
 * get_args - Fct that gets command from user
 *
 * @buffer: memory used to retrieve input
 * Return: (tableau d'argument)
 */

char **get_args(char *buffer)
{
	char **args = NULL, *arg = NULL;
	int i = 0;

	args = malloc(sizeof(char *) * (word_count(buffer) + 1));
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