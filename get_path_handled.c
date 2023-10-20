#include "shell.h"
/**
 * get_path_handled - handle path
 * @pth: the path command
 * Return: return (entire_path)
 */
char *get_path_handled(char *pth)
{
	int n;
	char *mk, *cmd_pth, *entire_path = NULL;
	struct stat st;

	for (n = 0; pth[n]; n++)
	{
		if (pth[n] == '/')
		{
			if (stat(pth, &st) == 0)
				return (_strdup(pth));

			return (NULL);
		}
	}
	entire_path = _getenv("PATH");
	if (entire_path == NULL)
		return (NULL);
	mk = strtok(entire_path, ":");
	while (mk != NULL)
	{
		cmd_pth = malloc(str_len(mk) + str_len(pth) + 2);
		if (cmd_pth)
		{
			str_copy(cmd_pth, mk), str_cat(cmd_pth, "/"), str_cat(cmd_pth, pth);
			if (stat(cmd_pth, &st) == 0)
			{
				free(entire_path);
				return (cmd_pth);
			}
			free(cmd_pth), cmd_pth = NULL;
			mk = strtok(NULL, ":");
		}
	}
	free(entire_path);
	return (NULL);
}
