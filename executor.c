#include "main.h"
/**
 *executor - exec the process
 *@buff: command entered to be executed
 *@env: the env in wich we exec commands
 */

int executor(char *buff, char **env, int line)
{
	int ret_path = 0;
	char **args = NULL;
	int (*statifior)(char *cmd, char **args, char **env);

	args = get_args(buff);
	if (args[0])
	{
		statifior = check_builtin(args[0]);
		if (statifior != NULL)
		{
			if (statifior(args[0], args, env) == 133)
			{
				free_args(args);
				return (133);
			}
		}
		else
		{
			ret_path = exec_path(args, env, line);
			free_args(args);
			return (ret_path);
		}
	}
	free_args(args);
	return (0);
}