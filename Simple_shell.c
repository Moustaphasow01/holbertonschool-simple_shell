#include "simple_shell.h"

/**
 * word_count - fct that count the number of word from user's input
 *
 * @str: input's string
 *
 * Return: Number of words
 */
size_t word_count(char *str)
{
	size_t i = 0, words = 0;
	int flag = OUT;

	while (str && str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			if (str[i] == '\n')
				str[i] = '\0';
			flag = OUT;
		}
		else if (flag == OUT)
		{
			flag = IN;
			words++;
		}
		i++;
	}
	return (words);
}

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

	args = (char **)malloc(sizeof(char *) * (word_count(buffer) + 1));
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

	(void)argc;
	(void)argv;

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
