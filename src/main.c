#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  printf("$ ");

  // Get user input
  char input[1024];
  fgets(input, sizeof(input), stdin);

  // Remove the trailing '\n'
  input[strcspn(input, "\n")] = '\0';

  printf("%s: command not found\n", input);

  while (strcmp(input, "exit")) {
    printf("$ ");

    // Get user input
    fgets(input, sizeof(input), stdin);

    // Remove the trailing '\n'
    input[strcspn(input, "\n")] = '\0';

    printf("%s: command not found\n", input);
  }

  return 0;
}
