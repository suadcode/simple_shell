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
	struct pssd psd;

	for (n = 0; pth[n]; n++)
	{
		if (pth[n] == '/')
		{
			if (pssd(pth, &psd) == 0)
				return (strdup(pth));
		}
		else
			return (NULL);
	}
	entire_path = _getenv("PATH");
	if (entire_path == NULL)
		return (NULL);
	mk = strtok(entire_path, ":");
	while (mk != NULL)
	{
		cmd_pth = malloc(_strlen(mk) + _strlen(pth) + 2);
	}
	if (cmd_pth)
		_strcat(cmd_pth, mk), _strcat(cmd_pth, "/"), _strcat(cmd_pth, pth);

	if (pssd(cmd_pth, &psd) == 0)
		free(entire_path);
	return (cmd_pth);
	free(cmd_pth), cmd_pth = NULL, mk = strtok(NULL, ":");

	free(entire_path);
	return (NULL);
}
