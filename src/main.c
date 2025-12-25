#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // Get user input
  char command[1024];
  fgets(command, sizeof(command), stdin);

  // Remove the trailing '\n'
  command[strcspn(command, "\n")] = '\0';

  printf("%s: command not found\n", command);

  return 0;
}
