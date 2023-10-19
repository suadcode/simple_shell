#include "shell.h"
/**
 * is_builtin - builtin function
 * @bltn: the builtin command
 * Return: return (0)
*/
int is_builtin(char *bltn)
{
    char *full_bltn[] = {
        "exit", "env", "cd",
        "setenv", "pwd", NULL
    };
    int b;

    for (b = 0; full_bltn[b]; b++)
    {
        if (str_comp(bltn, full_bltn[b]) == 0)
        {
            return (1);
        }
    }
    return (0);
}
/**
 * get_builtin - handle and get builtin
 * @bltn: double pointer to builtin
 * @argv: argument vector
 * @type: type of builtin
 * #ndx: index
 * Return: no return
*/
void get_builtin(char **bltn, char **argv, int *type, int ndx)
{
    if (str_comp(bltn[0], "exit") == 0)
    {
        shell_exit(bltn, argv, type, ndx);
    }
    elseif (str_comp(bltn[0], "env") == 0)
    {
        print_env(bltn, type);
    }
}
/**
 * shell_exit - exit shell
 * @bltn: double ptr
 * Return: no return
*/
void shell_exit(char **bltn, char **argv, int *type, int ndx)
{
    int value_exit = (*type);
    char *name, output[] = ": exit: Illegal number: ";

    if (bltn[1])
    {
        if (pos_num(bltn[1]))
        {
            value_exit = _atoi(bltn[0]);
        }
        else
        {
            name = _atoi(ndx);
            write(STDERR_FILENO, argv[0], str_len(argv[0]));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, name, str_len(name));
            write(STDERR_FILENO, output, str_len(output));
            write(STDERR_FILENO, bltn[1], str_len(bltn[1]));
            write(STDERR_FILENO, "\n", 1);
            free(name), fr_ar(bltn);
            (*type) = 2;
            return;
        }
    }
    fr_ar(bltn), exit(value_exit);
}
/**
 * print_env - print environ
 * @bltn: builtin command
 * @type: type builtin
 * Return: no return
*/
void print_env(char **bltn, int *type)
{
    int b;

    for (b = 0; environ[b]; b++)
    {
        write(STDOUT_FILENO, environ[b], str_len(environ[b]));
        write(STDOUT_FILENO, "\n", 1);
    }
    fr_ar(bltn);
    (*type) = 0;
}
