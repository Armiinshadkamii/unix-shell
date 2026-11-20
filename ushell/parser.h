
#ifndef UNIX_SHELL_PARSER_H
#define UNIX_SHELL_PARSER_H

#include <sys/types.h>
#include <stddef.h>
#include <string.h>

size_t parse_command(char *line, char *argv[], size_t max_args);

#endif //UNIX_SHELL_PARSER_H
