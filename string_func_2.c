#include "shell.h"
/**
 * *_strchr - locates a character in a string
 *@str: the string to be parsed
 *@chr: the character to look for
 *Return: (str) a pointer to the memory area s
 */
char *_strchr(char *str, char chr)
{
	while (*str++ != '\0')
	{
		if (*str == chr)
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{

	while (*needle)
	{
		if (*needle++ != *haystack++)
		{
			return (NULL);
		}
	}
	return ((char *)haystack);
}
/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{

	int x, lnth = 0;
	char *ret;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[lnth])
	{
		lnth++;
	}
	ret = malloc(sizeof(char) * (lnth + 1));

	if (!ret)
	{
		return (NULL);
	}
	for (x = 0; x <= lnth; x++)
	{
		ret[x] = str[x];
	}
	return (ret);
}
/**
 * _puts - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */
void _puts(char *str)
{

	int i = 0;

	if (!str)
	{
		return;
	}
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
	}
	return (1);
}
