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
