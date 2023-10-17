#include "shell.h"



/**
 * *_strchr - locates a character in a string
 *@str: the string to be parsed
 *@chr: the character to look for
 *Return: (str) a pointer to the memory area s
 */

char *_strchr(char *str, char chr)

{

	do {

	if (*str == chr)

	return (str);

	}

	while (*str++ != '\0');

	return (NULL);

}

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to check
 * Return: integer length of string
 */

int _strlen(char *str)

{

	int i = 0;


	if (!str)

	return (0);


	while (*str++)

	i++;

	return (i);

}


/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @str1: the first strang
 * @str2: the second strang
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */

int _strcmp(char *str1, char *str2)

{

	while (*str1 && *str2)

	{

	if (*str1 != *str2)

	return (*str1 - *str2);

	str1++;

	str2++;

	}

	if (*s1 == *s2)

	return (0);

	else

	return (*str1 < *str2 ? -1 : 1);

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

	if (*needle++ != *haystack++)

	return (NULL);

	return ((char *)haystack);

}


/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 * Return: pointer to destination buffer
 */

char *_strcat(char *dest, char *src)

{

	char *del = dest;


	while (*dest)

	dest++;

	while (*src)

	*dest++ = *src++;

	*dest = *src;

	return (del);


}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *str)
{

	int length = 0;

	char *ret;


	if (str == NULL)

	return (NULL);

	while (*str++)

	length++;

	ret = malloc(sizeof(char) * (length + 1));

	if (!ret)

	return (NULL);

	for (length++; length--;)

	ret[length] = *--str;

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

	return;

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

	buf[i++] = c;

	return (1);

}
