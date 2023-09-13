#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Fork and wait example
 *
 * This program demonstrates the use of fork() to create a child process and wait()
 * to wait for the child process to complete.
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid; // Stores the process ID of the child process
    int status;     // Stores the exit status of the child process

    // Fork a new process
    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Error:"); // Handle fork failure
        return (1);
    }

    if (child_pid == 0) // Child process
    {
        printf("Wait for me, wait for me\n");
        sleep(3); // Simulate some work in the child process
    }
    else // Parent process
    {
        // Wait for the child process to complete and get its exit status
        wait(&status);

        printf("Oh, it's all better now\n");
    }

    return (0);
}

