#ifndef SHELL_H
#define SHELL_H

#define STDIN_FILENO
#define STDOUT_FILENO
#define STDERR_FILENO 2
#define dlmtr ""
#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#define WRITE_BUF_SIZE 1024

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
#define BUF_FLUSH -1
#define MAX_TOkENS 1024
#define PROMPT "$ "
#define MAX_ARGS 1024
#define MAX_COMMANDS 1024
#define PATH_SEPARATOR ":"
#define PATH_MAX_LENGTH 4096

extern char **environ;

char *get_new_line(void);
int main(int argc, char **argv);
char **check_tokenizer(char *new_line);
void fr_ar(char **arr);
int shell_execute(char **sh_arr, char **argv);
char *get_path_handled(char *pth);
char *_getenv(const char *value);
int shell_excute(char **sh_arr, char **argv);
int betty_checks(void);
char *str_cat(char *dest, char *sorc);
int str_comp(char *s1, char *s2);
int str_len(char *str);
size_t str_tocmp(char *s1, char *s2, size_t num);
char *str_copy(char *dest, char *sorc);
char *_strncat(char *dest, char *src, int n);
char *_strchr(char *str, char chr);
char *starts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);

char *_itoa(int n);
void print_error(char *value, char *cmnd, int ndx);
void rev_str(char *str, int lnth);

#endif
