#include <stdio.h>

int main() {
  char line[100];

  printf("$ ");
  fgets(line, sizeof(line), stdin);

  printf("You entered: %s\n", line);

  return 0;
}

