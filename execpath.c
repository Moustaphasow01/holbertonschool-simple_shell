#include "main.h"

/**
 * @brief
 *
 */

int exec_path(char **args, char **env)
{
	pid_t child;
	char *fullpath = NULL, *PATH;

	PATH = strdup(getenv("PATH"));
	fullpath = pathfinder(args[0], PATH);
	free(PATH);
	child = fork();
	if (child == 0)
	{
		if ((execve(fullpath, args, env)) == -1)
		{
			write(STDERR_FILENO, "hsh: ", 6);
			write(STDERR_FILENO, args[0], strlen(args[0]));
			write(STDERR_FILENO, ": not found\n", 13);
			free_args(args);
			free(fullpath);
			return (134);
		}
	}

	else if (child > 0)
		wait(NULL);
	else
	{
		free_args(args);
		free(fullpath);
		return (134);
	}
	free(fullpath);
	return (0);
}