#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  char input[1024];
  while (1) {
    printf("$ ");

    // Get user input
    if (fgets(input, sizeof(input), stdin) == NULL)
      break;

    // Remove trailing newline
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "exit") == 0)
      break;

    // Parse command from input
    char *space_ptr = strchr(input, ' ');
    char command[1024];

    if (space_ptr != NULL) {
      size_t cmd_len = space_ptr - input;
      strncpy(command, input, cmd_len);
      command[cmd_len] = '\0';
    } else {
      // No space, whole input is command
      strcpy(command, input);
    }

    if (strcmp(command, "echo") == 0) {
      if (space_ptr != NULL) {
        printf("%s\n", space_ptr + 1);
      } else {
        printf("\n");
      }
    } else if (strcmp(command, "type") == 0) {
      if (space_ptr != NULL) {
        char *type_command = space_ptr + 1;
        if (strcmp(type_command, "echo") == 0 ||
            strcmp(type_command, "exit") == 0 ||
            strcmp(type_command, "type") == 0) {
          printf("%s is a shell builtin\n", type_command);
        } else {
          printf("%s: not found\n", type_command);
        }
      }
    } else {
      printf("%s: command not found\n", command);
    }
  }

  return 0;
}
