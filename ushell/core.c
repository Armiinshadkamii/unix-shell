#include "core.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

int execute_command(char *argv[]) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        /*
         * If execvp() succeeds, the child process is replaced by the new program.
         * It never reaches the next line.
         * If execvp() fails, execution continues to perror(),
         * then _exit() terminates the child.
         */
        execvp(argv[0], argv);
        perror("execvp error");
        _exit(EXIT_FAILURE);
    }
    // Parent process
    int status;
    pid_t waitpid_result;

    do {
        waitpid_result = waitpid(pid, &status, 0);
    } while (waitpid_result == -1 && errno == EINTR);

    if (waitpid_result == -1) {
        perror("waitpid error");
        return EXIT_FAILURE;
    }

    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }

    return EXIT_FAILURE;
}
