#include "shell.h"
/**
 * main - main shell function
 * @argc: argument count
 * @argv: argument vector
 * Return: return
*/
int main(int argc, char **argv)
{
	char *new_line = NULL;
	char **cmd_nw_ln = NULL;
	int type = 0, ndx = 0;
	(void)argc;

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
		type = shell_execute(cmd_nw_ln, argv);
	}
	return (type);
}
