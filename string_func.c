#include "shell.h"

/**
 * str_cat - copy string to another string.
 * @dest: destination string
 * @sorc: source string
 * Return: dest
 */

char *str_cat(char *dest, char *sorc)
{
	int d = 0;
	int s = 0;

	while (dest[d] != '\0')
	{
	d++;
	}
	while (sorc[s] != '\0')
	{
	dest[d] = sorc[s];
	d++;
	s++;
	}
	dest[d] = '\0';
	return (dest);
}

/**
 * str_comp - compare the values of a string
 * @s1: first compare string
 * @s2: second compare  string
 * Return: 0
 */

int str_comp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != '\0' && s2[a] != '\0'; a++)
	{
	if (s1[a] != s2[a])
	{
	return ((int)s1[a] - s2[a]);
	}
	}
	return (0);
}
/**
 * str_len - copies the string pointed to by sorc into dest
 * @s: A pointer
 * Return: char a pointer to dest
 */

int str_len(char *s)
{
	int chr = 0;

	while (*(s + chr) != '\0')
	{
	chr++;
	}

	return (chr);
}

/**
 * str_tocmp -  function that compares two strings.
 * @s1: first compare string
 * @s2: second compare string
 * @num: number of characters
 * Return: result
 */

size_t str_tocmp(char *s1, char *s2, size_t num)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0' && j < num; j++)
	{
	i = s1[j] - s2[j];

	if (i != 0)
	{
	return (i);
	}
	}
	return (0);
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

	while (*(sorc + i) != '\0')
	{
	*(dest + i) = *(sorc + i);
	++i;
	}
	*(dest + i) = *(sorc + i);

	return (dest);
}
