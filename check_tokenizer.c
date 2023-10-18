#include "shell.h"
/**
 * check_tokenizer - to check the tokenizer
 * @new_line: new line
 * Return: return the command new line
*/
char **check_tokenizer(char *new_line)
{
	char *tkn = NULL;
	char *pass = NULL;
	char **cmd_nw_ln = NULL;
	int nmbr = 0;
	int i = 0;

	if (!new_line)
	{
		return (NULL);
	}

	tkn = strtok(new_line, dlmtr);
	pass = _strdup(new_line);
	if (tkn == NULL)
	{
		fr_ar(&pass);
		return (NULL);
	}
	while (tkn)
	{
		nmbr++;
		tkn = strtok(NULL, dlmtr);
	}
	cmd_nw_ln = malloc(sizeof(char *) * (nmbr + 1));
	if (!cmd_nw_ln)
	{
		fr_ar(&new_line);
		return (NULL);
	}
	tkn = strtok(new_line, dlmtr);
	while (tkn)
	{
		cmd_nw_ln[i] = _strdup(tkn), tkn = strtok(NULL, dlmtr);
		i++;
	}
	fr_ar(&new_line);
	cmd_nw_ln[i] = NULL;
	return (cmd_nw_ln);
}
