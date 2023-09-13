#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello,World,How,Are,You";
    const char delimiters[] = ",";

    // Tokenize the string using strtok
    char *token = strtok(str, delimiters);

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delimiters); // Continue tokenization
    }

    return 0;
}

