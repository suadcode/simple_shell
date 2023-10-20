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
	char *new_line = NULL, **cmd_nw_ln = NULL;
	int type = 0, ndx = 0;
	(void)argc;

	while (1)
	{
		new_line = get_new_line();
		if (new_line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (type);
		}
		ndx++;
		cmd_nw_ln = check_tokenizer(new_line);
		if (!cmd_nw_ln)
			continue;
		if (is_builtin(cmd_nw_ln[0]))
		{
			if (str_comp(cmd_nw_ln[0], "setenv") == 0)
				if (cmd_nw_ln[1] != NULL && cmd_nw_ln[2] != NULL)
					set_env(&env, cmd_nw_ln[1], cmd_nw_ln[2]);
				else
					write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
			else if (str_comp(cmd_nw_ln[0], "unsetenv") == 0)
				if (cmd_nw_ln[1] != NULL)
					unset_env(&env, cmd_nw_ln[1]);
				else
					write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 25);
			else
				get_builtin(cmd_nw_ln, argv, &type, ndx);
		}
		else
			type = shell_execute(cmd_nw_ln, argv, env, ndx);
	}
	return (type);
}
