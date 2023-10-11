#ifndef SHELL_H
#define SHELL_H

#define STDIN_FILENO
#define STDOUT_FILENO
#define dlmtr ""
#define GNU_SOURCE

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <limits.h>
#include <fcntl.h>


#define BUFFER_SIZE 1024
#define MAX_TOkENS 1024
#define PROMPT "$ "
#define MAX_ARGS 1024
#define MAX_COMMANDS 1024
#define PATH_SEPARATOR ":"
#define PATH_MAX_LENGTH 4096


extern char **environ;

char *get_new_line(void);


#endif
