#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  char input[1024];
  while (strcmp(input, "exit")) {
    printf("$ ");

    // Get user input
    fgets(input, sizeof(input), stdin);

    // Remove the trailing '\n'
    input[strcspn(input, "\n")] = '\0';

    char *echo = strstr(input, "echo");
    if (echo) {
      printf("%s\n", echo + sizeof("echo"));
    } else {
      printf("%s: command not found\n", input);
    }
  }

  return 0;
}
