#include "shell.h"
/**
 * rev_str - reverse string
 * @str: string
 * @lnth: length
 * Return: no return
*/
void rev_str(char *str, int lnth)
{
	int x = 0, z = (lnth - 1);
	char pass;

	while (str[lnth] != '\0')
	{
		lnth++;
	}
	while (x < z)
	{
		pass = str[x];
		str[x] = str[z];
		str[z] = pass;
		x++;
		z--;
	}
}
