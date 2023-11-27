#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>

#include "exeCommand.h"

int exeCommand(char *command, ssize_t command_size) {
    int pid = fork();
    int status;

    if (pid == 0) {
        // Child process
        execlp(command, command, NULL);
        exit(EXIT_SUCCESS);

    } else {
        // Parent process
        wait(NULL);
    }
    return 0;
}