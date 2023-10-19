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
 * Return: return
 */
int shell_execute(char **sh_arr, char **argv)
{
	pid_t scnd;
	int type;

	scnd = fork();
	if (scnd == 0)
	{
		if (execve(sh_arr[0], sh_arr, environ) == -1)
		{
			perror(argv[0]), fr_ar(sh_arr), exit(127);
		}
		else
		{
			waitpid(scnd, &type, 0), fr_ar(sh_arr);
		}
	}
	return (WEXITSTATUS(type));
}
