#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <strings.h>

int main() {
    pid_t shell_pid = getpid();
    printf("Shell PID: %d\n", shell_pid);

    while (1) {
        printf("Shell> ");
        char command[256];
        fgets(command, sizeof(command), stdin);

        // Remove newline character from the input
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        // Fork a child process to execute the command
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("Fork failed");
            exit(1);
        } else if (child_pid == 0) {
            // This code block is executed by the child process
            printf("Child process PID: %d\n", getpid());
            // Execute the command using exec functions
            execlp(command, command, NULL);
            perror("Exec failed");
            exit(1);
        } else {
            // This code block is executed by the parent process
            int status;
            waitpid(child_pid, &status, 0);
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}

