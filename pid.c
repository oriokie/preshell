#include <stdio.h>
#include <unistd.h>
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid, parent;

    my_pid = getpid();
	parent = getppid();

    printf("Child: %u\n", my_pid);
	printf("Parent: %u\n", parent);

    return (0);
}
