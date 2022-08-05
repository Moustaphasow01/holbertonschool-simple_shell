#include "main.h"

/**
 * @brief
 *
 */

int exec_path(char **args, char **env, int line)
{
	pid_t child;
	char *fullpath = NULL, *PATH;

	PATH = getenv("PATH");

	if (!PATH && (execve(args[0], args, env)) == -1)
	{
		printf("./hsh: %d: %s: not found\n", line, args[0]);
		free(fullpath);
		return (134);
	}
	else
	{
		PATH = strdup(PATH);
		fullpath = pathfinder(args[0], PATH);
		free(PATH);
		child = fork();
		if (child == 0)
		{
			if ((execve(fullpath, args, env)) == -1)
			{
				printf("./hsh: %d: %s: not found\n", line, args[0]);
				free(fullpath);
				return (134);
			}
		}

		else if (child > 0)
			wait(NULL);
		else
		{
			free(fullpath);
			return (134);
		}
	}
	if (fullpath)
		free(fullpath);
	return (0);
}