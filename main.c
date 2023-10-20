#include "shell.h"
/**
 * main - main shell function
 * @argc: argument count
 * @argv: argument vector
 * @env: environ
 * Return: return
*/
int main(int argc, char **argv, char **env)
{
	char *new_line = NULL;
	char **cmd_nw_ln = NULL;
	int type = 0, ndx = 0;
	(void)argc;
	(void)env;

	while (1)
	{
		new_line = get_new_line();
		if (new_line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (type);
		}
		ndx++;
		cmd_nw_ln = check_tokenizer(new_line);
		if (!cmd_nw_ln)
		{
			continue;
		}
		if (is_builtin(cmd_nw_ln[0]))
		{
			get_builtin(cmd_nw_ln, argv, &type, ndx);
		}
		else
		{
			type = shell_execute(cmd_nw_ln, argv, ndx);
		}
	}
	return (type);
}
