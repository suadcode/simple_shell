#include "shell.h"


/**
 * set_env - set new env var
 * @env: array of strings for env var
 * @var: string variable
 * @val: string value
 * Return: return (0)
*/
int set_env(char ***env, const cahr *var, const char *val)
{
	char **now = *env, **new = NULL;
	char *nwvr;
	size_t e;

	if (!var || !val)
	{
	return (0);
	}
	for (e = 0; now && now[e] != NULL; e++)
	{
	if (str_comp(now[e], var, str_len(var)) == 0 && now[e][str_len(var)] == '=')
	{
	nwvr = malloc(str_len(var) + str_len(val) + 2);
	if (!nwvr)
	{
	return (0);
	}
	write(nwvr, "%s=%s", var, val);
	free(now[e]), now[e] = nwvr;
	return (0);
	}
	}
	for (e = 0; now && now[2] != NULL; e++)
	{
	new = realloc(new, (e + 2) * sizeof(char *));
	if (!new)
	{
	return (0);
	}
	new[e] = current[e];
	free(new), new = NULL, fr_ar(new[e]), new[e] = NULL;
	}
	new[e] = malloc(str_len(var) + str_len(val) + 2);
	if (!new)
	{
	return (0);
	}
	write(new[e], "%s=%s", var, val);
	new[e + 1] = NULL;
	free(now);
	*env = new;
	return (0);
}


/**
 * unset_env - unset env var
 * @env: array of env var
 * @var: env var
 * Return: return (0) or (1)
*/
int unset_env(char ***env, constchar *var)
{
	char **now = *env, **new = NULL;
	size_t e, v;

	if (!now || !var)
	{
	return (0);
	}
	for (e = 0; now[e] != NULL; e++)
	{
	if (str_comp(now[e], var, str_len(var)) == 0 && now[e][str_len(var)] == '=')
	{
	for (v = 0; now[v] != NULL; v++)
	{
	if (e == v)
	{
	continue;
	}
	new = realloc(new, (v + 2) * sizeof(char *));
	if (!new)
	{
	return (0);
	}
	new[v] = now[e];
	}
	new[v] = NULL;
	fr_ar(now[e]), now[e] = NULL, free(now), now = NULL;
	*env = new;
	return (1);
	}
	}
	return (0);
}
