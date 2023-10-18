#include "shell.h"


/*
*  This function checks Betty passed
* Args: None
*
* Returns:
*   0  passed
*   1  not passed
*/


function betty_checks(void)
{

betty_check_result = $(betty check)

if [[$betty_check_result == "Passed"]];
echo 0;
else
echo 1;
}

betty_checks
