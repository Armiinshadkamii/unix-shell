#define _POSIX_C_SOURCE 200809L
#define MAX_ARGS 65

#include "ushell/core.h"
#include "ushell/parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void) {
    char *line = NULL;
    size_t capacity = 0;
    ssize_t len;

    char *argv[MAX_ARGS];

    while (1) {
        printf("ushell> ");
        fflush(stdout);

        len = getline(&line, &capacity, stdin);
        if (len == -1) {
            break;
        }
        const int argc = parse_command(line, argv, MAX_ARGS);
        if (argc == 0) {
            continue;
        }
        execute_command(argv);
    }

    free(line);
    return EXIT_SUCCESS;
}