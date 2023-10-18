#include "shell.h"
/**
 * _getenv - get environ
 * @value: the string env
 * Return: return(NULL)
*/
char *_getenv(char *value)
{
	char *pass;
	char *env;
	char *var;
	int v;

	for (v = 0; environ[v]; v++)
	{
		pass = _strdup(environ[v]);
		env = strtok(pass, "=");
		if (str_comp(env, value) == 0)
		{
			var = strtok(NULL, "\n");
			env = _strdup(var);
			free(pass);
			return (env);
		}
		free(pass);
		pass = NULL;
	}
	return (NULL);
}
