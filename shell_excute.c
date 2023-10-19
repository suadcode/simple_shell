#include "shell.h"
/**
 * fr_ar - function to free array
 * @arr: array to be free
 * Return: no return
 */
void fr_ar(char **arr)
{
	int x = 0;

	if (!arr)
	{
		return;
	}
	for (x = 0; arr[x]; x++)
	{
		free(arr[x]);
		arr[x] = NULL;
	}
	free(arr);
	arr = NULL;
}
/**
 * shell_execute - execute shell
 * @sh_arr: arrays of shell
 * @argv: argument vector
 * @ndx: index
 * Return: return
 */
int shell_execute(char **sh_arr, char **argv, int ndx)
{
	char *cmd_pth;
	pid_t scnd;
	int type;

	cmd_pth = get_path_handled(sh_arr[0]);
	if (!cmd_pth)
	{
		print_error(argv[0], sh_arr[0], ndx);
		fr_ar(sh_arr);
		return (127);
	}
	scnd = fork();
	if (scnd == 0)
	{
		if (execve(cmd_pth, sh_arr, environ) == -1)
		{
			free(cmd_pth), cmd_pth = NULL;
			fr_ar(sh_arr), exit(127);
		}
	}
	else
	{
		waitpid(scnd, &type, 0), fr_ar(sh_arr);
		free(cmd_pth), cmd_pth = NULL;
	}
	return (WEXITSTATUS(type));
}
