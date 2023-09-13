#include <stdio.h>
#include <unistd.h>

int main(void) {
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    char *envp[] = {
        "PATH=/usr/bin:/bin", // Example environment variable
        NULL                  // End of the environment array
    };

    printf("Before execve\n");
    
    if (execve(argv[0], argv, envp) == -1) {
        perror("Error:");
    }
    
    printf("After execve\n"); // This will not be reached if execve succeeds

    return 0;
}

