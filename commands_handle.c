#include "shell.h"
/**
 * parse_execute - parse and execute
 * @value: the inputs
 * Return: no return
*/
void parse_execute(char *value)
{
	char *tkns[MAX_TOKENS], *tkn;
	int t, nmbr = 0;

	tkn = strtok(value, CMNDS);
	while (tkn != NULL && nmbr < MAX_TOKENS - 1)
	{
		tkns[nmbr++] = tkn;
		tkn = strtok(NULL, CMNDS);
	}
	tkns[nmbr] = NULL;
	for (t = 0; t < nmbr; t++)
	{
		change_variable(tkns[t], "$?", "last_code_exit");
		change_variable(tkns[t], "$$", "id_process");
	}
	commands_execute(tkns);
}
/**
 * commands_execute - execute commands
 * @args: arguments
 * Description: execute commands
 * Return: no return
*/
void commands_execute(char **args)
{
	pid_t scnd;
	pid_t frst;
	int type;
	(void)frst;

	scnd = fork();
	if (scnd == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			print_error("simple_shell", args[0], 0);
		}
		exit(EXIT_FAILURE);
	}
	else if (scnd < 0)
	{
		print_error("simple_shell", "fork", 0);
	}
	else
	{
		do {
			frst = waitpid(scnd, &type, WUNTRACED);
		} while (!WIFEXITED(type) && !WIFSIGNALED(type));
	}
}
/**
 * change_variable - change variables
 * @token: token
 * @var: variable
 * @val: value
 * Retuen: no return
*/
void change_variable(char *token, char *var, char *val)
{
	char *sep = strchr(token, *var);
	int value = str_len(val);
	int variable = str_len(var);
	int sep_var = str_len(sep + str_len(var));

	if (sep != NULL)
	{
		memmove(sep + value, sep + variable, sep_var + 1);
		memcpy(sep, val, str_len(val));
	}
}
