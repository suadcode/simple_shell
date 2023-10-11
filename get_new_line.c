#include "shell.h"
/**
 * get_new_line - get new line
 * Description: print new line
 * Return: return (NULL)
*/
char *get_new_line(void)
{
	char *new_line = NULL;
	size_t lngth = 0;
	ssize_t nmbr;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	nmbr = get_new_line(&new_line, &lngth, stdin);
	if (nmbr == -1)
	{
		free(new_line);
		return (NULL);
	}
	return (NULL);
}
