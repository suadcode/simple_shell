#include "shell.h"
/**
 * main - main shell function
 * @argc: argument count
 * @argv: argument vector
 * Return: return
*/
int main(int argc, char **argv)
{
	(void) argc;
	char *new_line = NULL;
	char **cmd_nw_ln = NULL;
	int type = 0, ndx = 0;

	while (true)
	{
		new_line = get_new_line();
		if (new_line == NULL)
		{
			if (is_ty(STDIN_FILENO))
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
		type = shell_excute(cmd_nw_ln, argv, ndx);
	}
}
