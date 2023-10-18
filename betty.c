#include "shell.h"
/*
 *  This function checks Betty passed
 * Args: None
 *
 * Returns:
 *   0  passed
 *   1  not passed
 */
int *betty_checks(void)
{
    char *betty_check_result = betty_checks;

    if (str_comp(betty_checks, "Passed") == 0)
        _putchar('0\n');
    else
        _putchar('1\n');

    return (0);
}
