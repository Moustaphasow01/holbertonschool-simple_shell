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

	char *buffer = NULL, **args = NULL;
	size_t size = 0;
	ssize_t read = 0;
	pid_t cpid = 0;

	(void)env;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("> ");
		read = getline(&buffer, &size, stdin);
		if (read != -1)
		{
			args = get_args(buffer);
			if (args[0])
				test_args();
			free_args(args);
		}
		else
		{
			free(buffer);
			return (0);
		}
	}
	return (0);
}
