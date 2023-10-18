#include "shell.h"

/*
 *  This function checks Betty passed
 * Args: None
 *
 * Returns:
 *   0  passed
 *   1  not passed
 */
int betty_checks(void)
{
    char *expected_result = "Passed";
    char *actual_result = "checked";
    int result;

    result = str_comp(actual_result, expected_result);

    printf("Result: %d\n", result);

    return (result);
}
