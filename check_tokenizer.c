#include "shell.h"
/**
 * check_tokenizer - to check the tokenizer
 * @new_line: new line
 * Return: return the command new line
 */
char **check_tokenizer(char *new_line)
{
	char *tkn = NULL, *pass = NULL;
	char **cmd_nw_ln = NULL;
	int nmbr = 0, i = 0;

	if (!new_line)
	{
		return (NULL);
	}
	pass = _strdup(new_line);
	tkn = strtok(new_line, DLMTR);
	if (tkn == NULL)
	{
		free(new_line), new_line = NULL;
		free(pass), pass = NULL;
		return (NULL);
	}
	while (tkn)
	{
		nmbr++;
		tkn = strtok(NULL, DLMTR);
	}
	free(pass), pass = NULL;
	cmd_nw_ln = malloc(sizeof(char *) * (nmbr + 1));
	if (!cmd_nw_ln)
	{
		free(new_line), new_line = NULL;
		return (NULL);
	}
	tkn = strtok(new_line, DLMTR);
	while (tkn)
	{
		cmd_nw_ln[i] = _strdup(tkn), tkn = strtok(NULL, DLMTR);
		i++;
	}
	free(new_line), new_line = NULL;
	cmd_nw_ln[i] = NULL;
	return (cmd_nw_ln);
}
