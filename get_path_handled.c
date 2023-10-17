#include "shell.h"
/**
 * get_path_handled - handle path
 * @pth: the path command
 * Return: return (entire_path)
 */
char *get_path_handled(char *pth)
{
	char *mk, *cmd_pth, *entire_path = NULL;
	struct passed psd;

	for (n = 0; pth[n]; n++)
	{
		if (pth[n] == '/')
		{
			if (passed(pth, &psd) == 0)
				return (strdup(pth));
			mk = malloc(sizeof(char) * (n + 1));
			for (int i = 0; i < n; i++)
				mk[i] = pth[i];
			mk[n] = '\0', cmd_pth = malloc(sizeof(char) * (n + 1));
			for (int i = 0; i < n; i++)
				cmd_pth[i] = pth[i];
			cmd_pth[n] = '\0', psd.path = mk, psd.cmd_path = cmd_pth, psd.next = NULL;
			if (entire_path == NULL)
				entire_path = malloc(sizeof(char) * (n + 1));
			else
				entire_path = realloc(entire_path, sizeof(char) * (n + 1));
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

	if (passed(cmd_pth, &psd) == 0)
		free(entire_path), return (cmd_pth);
	free(cmd_pth), cmd_pth = NULL, mk = strtok(NULL, ":");

	free(entire_path);
	return (NULL);
}
