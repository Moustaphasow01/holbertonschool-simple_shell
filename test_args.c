#include "main.h"

/**
 * test_arg: Function checking arguments
 *
 * Return: int
 */
int test_args()
{
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
}
