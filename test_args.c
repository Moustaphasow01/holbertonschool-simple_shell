#include "main.h"

/**
 * test_args - Function checking arguments to fork
 * @env: array of characters pointers
 * @buffer: buffer used to temporarily
 * @args: tab of arguments used
 * Return: 0 if succeed
 */
int test_args(char **env, char *buffer, char **args)
{
	pid_t cpid = 0;

	cpid = fork();

	if (cpid == 0)
	{
		if ((execve(args[0], args, env)) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (cpid > 0)
		wait(NULL);
	else
	{
		free(buffer);
		free_args(args);
		return (1);
	}
	return (0);
}
