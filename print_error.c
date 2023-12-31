#include "shell.h"
/**
 * print_error - print errors
 * @value: the value
 * @cmnd: command in shell
 * @ndx: index
 * Return: no return
 */
void print_error(char *value, char *cmnd, int ndx)
{
	char *name;
	char output[] = ": not found";

	name = _itoa(ndx);

	write(STDERR_FILENO, value, str_len(value));
	write(STDERR_FILENO, ":", 2);
	write(STDERR_FILENO, name, str_len(name));
	write(STDERR_FILENO, ":", 2);
	write(STDERR_FILENO, cmnd, str_len(cmnd));
	write(STDERR_FILENO, output, str_len(output));

	free(name);
}
/**
 * _itoa - int to array
 * @n: integer
 * Return: buuffer
*/
char *_itoa(int n)
{
	char buf[20];
	int x = 0;

	if (n == 0)
	{
		buf[x] = '0';
		x++;
	}
	else
	{
		while (n > 0)
		{
			buf[x++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buf[x] = '\0';
	rev_str(buf, x);
	return (_strdup(buf));
}
/**
 * pos_num - check if number is positive
 * @str: string
 * Return: return (1)
*/
int pos_num(char *str)
{
	int n;

	if (!str)
	{
		return (0);
	}
	for (n = 0; str[n]; n++)
	{
		if (str[n] < '0' || str[n] > '9')
		{
			return (0);
		}
	}
	return (1);
}
/**
 * _atoi - array to integer
 * @str: string
 * Return: return (num)
*/
int _atoi(char *str)
{
	int n, num = 0;

	for (n = 0; str[n]; n++)
	{
		num *= 10;
		num += (str[n] - '0');
	}
	return (num);
}
