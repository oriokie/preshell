#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Prints all the command line arguments
 *
 * @ac: The number of command line arguments
 * @av: The array of command line arguments
 *
 * Returns 0 on success
 */
int main(int ac, char **av) {
  int i;

  for (i = 1; av[i] != NULL; i++) {
    printf("Argument %d: %s\n", i, av[i]);
  }

  return 0;
}

