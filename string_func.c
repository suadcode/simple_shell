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
