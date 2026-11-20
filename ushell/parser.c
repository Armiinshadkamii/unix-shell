#include "parser.h"

/*
char input[] = "echo hello world";

char *token = strtok(input, " ");

while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, " ");
}
 */

#include <stddef.h>
#include <string.h>

size_t parse_command(char *line, char *argv[], size_t max_args) {
    char *token = strtok(line, " \t\n");
    size_t i = 0;
    if (max_args == 0) return 0;

    while (token != NULL && i < max_args - 1) { // reserve space for null
        argv[i] = token;
        token = strtok(NULL, " \t\n");

        i++;
    }
    argv[i] = NULL; // execvp requires the array to be NULL terminated
    return i;
}