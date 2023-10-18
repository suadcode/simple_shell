#include "shell.h"


/*
* This function checks if Betty passed
* Args: None
* Returns:
*   0 if passed
*   1 if not passed
*/


function betty_checks(void)
{

betty_check_result = $(betty check)

if [[$betty_check_result == "Passed"]];
echo 0;
else
echo 1;
}

betty_checks()

