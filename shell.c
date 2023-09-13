#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        // Display a prompt and read user input
        printf("$ ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit if there's no input (e.g., EOF)
        }

        // Remove the newline character from the input
        size_t input_length = strlen(input);
        if (input_length > 0 && input[input_length - 1] == '\n') {
            input[input_length - 1] = '\0';
        }

        // Fork a child process
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("Error:");
            return 1;
        }

        if (child_pid == 0) {
            // Child process code
            if (strlen(input) == 0) {
                exit(0); // Empty input, just exit the child process
            }

            // Use execve to execute the command with its full path
            if (execve(input, NULL, NULL) == -1) {
                perror("execve error");
                exit(1);
            }
        } else {
            // Parent process code
            int status;
            waitpid(child_pid, &status, 0); // Wait for the child to exit
        }
    }

    return 0;
}

