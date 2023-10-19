#include "shell.h"
/**
 * str_cat - copy string to another string.
 * @dest: destination string
 * @sorc: source string
 * Return: dest
 */
char *str_cat(char *dest, char *sorc)
{
	char *pass = dest;

	while (*pass)
	{
		pass++;
	}
	while (*sorc)
	{
		*pass = *sorc;
		pass++;
		sorc++;
	}
	*pass = '\0';
	return (dest);
}
/**
 * str_comp - compare the values of a string
 * @s1: first compare string
 * @s2: second compare  string
 * Return: cmpr
 */
int str_comp(char *s1, char *s2)
{
	int cmpr;

	cmpr = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
		{
			break;
		}
		s1++;
		s2++;
		cmpr = ((int)*s1 - (int)*s2);
	}
	return (cmpr);
}
/**
 * str_len - copies the string pointed to by sorc into dest
 * @str: A pointer
 * Return: char a pointer to dest
 */
int str_len(char *str)
{
	int lnth = 0;

	if (!str)
	{
		return (NULL);
	}
	while (str[lnth])
	{
		lnth++;
	}
	return (lnth);
}
/**
 * str_copy - copies the string pointed to by sorc into dest
 * @dest: destination of copy
 * @sorc: source of copy
 * Return: dest
 */
char *str_copy(char *dest, char *sorc)
{
	int i = 0;

	while (sorc[i])
	{
		dest[i] = sorc[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * *_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;
	char *str = dest;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
	{
		dest[i] = '\0';
	}
	return (str);
}
