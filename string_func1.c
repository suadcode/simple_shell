#include "shell.h"
/**
 * rev_str - reverse string
 * @str: string
 * Return: no return
*/
void rev_str(char *str, int lnth)
{
	int x;
	char pass;

	while (str[lnth] != '\0')
	{
		lnth++;
	}
	while (x = 0, x < lnth / 2)
	{
		pass = str[x];
		str[x] = str[lnth - x - 1];
		str[lnth - x - 1] = pass;
	}
}
