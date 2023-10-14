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

    while (dest[d] != '\0') {
        d++;
    }
    while (sorc[s] != '\0') {
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
 * str_len copies the string pointed to by sorc into dest
 * @s: A pointer
 * Return: char a pointer to dest
 */

int str_len(char *s)
{
    int char = 0;

    while (*(s + char) != '\0') {
        char++;
    }

    return (char);
}
