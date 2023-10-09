#include <stdio.h>
#include <unistd.h>
/**
 * main - PID & PPID
 * Return: Always 0
*/
int main(void)
{
	pid_t my_pid, my_ppid;

	my_pid = getpid();
	my_ppid = getppid;

	printf("pid = %u\nppid = %u\n", my_pid, my_ppid);
	return (0);
}