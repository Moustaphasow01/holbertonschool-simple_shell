#include "main.h"
/**
 * main - Main function
 *
 * @argc: __attribute__
 * @argv: value per arguments
 * @env: array of character pointers
 *
 * Return: (0) if succeed
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	(void)argc;
	(void)argv;
	char *buffer = NULL, **args = NULL;
	size_t size = 0;
	ssize_t read = 0;
	pid_t cpid = 0;

	while (1)
	{
		read = getline(&buffer, &size, stdin);
		printf("$ ");
		if ((read) != -1)
		{
			cpid = fork();
			if (cpid == 0)
			{
				args = get_args(buffer);
				if ((execve(args[0], args, env)) == -1)
				{
					perror(args[0]);
					exit(EXIT_FAILURE);
				}
			}
			else if (cpid > 0)
			{
				wait(NULL);
			}
			else
			{
				free(buffer);
				return (1);
			}
		}
		else
		{
			free(buffer);
			return (1);
		}
	}
	return (0);
}