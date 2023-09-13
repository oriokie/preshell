#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    // Command string to tokenize
    char command[] = "ls -l /tmp";

    // Tokenize the command into individual arguments
    char *args[4]; // Maximum 4 arguments: command, arg1, arg2, NULL
    char *token = strtok(command, " ");
    int arg_count = 0;

    while (token != NULL && arg_count < 3) {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL; // Null-terminate the argument array

    // Loop to create and wait for 5 child processes
    for (int i = 0; i < 5; i++) {
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("Error:");
            return 1;
        }

        if (child_pid == 0) {
            // Child process code
            printf("Child %d executing ls -l /tmp:\n", i + 1);

            // Use execve to execute the command with its arguments
            if (execve("/bin/ls", args, NULL) == -1) {
                perror("execve error");
                exit(1);
            }
        } else {
            // Parent process code
            int status;
            waitpid(child_pid, &status, 0); // Wait for the child to exit
            printf("Child %d has exited\n", i + 1);
        }
    }

    return 0;
}

