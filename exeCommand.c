#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>

#include "exeCommand.h"

char prompt[PROMPT_SIZE];

// Function to execute a command
void exeCommand(char *cmd) {
    pid_t pid;
    int status;

    pid = fork(); // Fork a new process

    if (pid == -1) {
        perror("Fork error \n");
        exit(EXIT_FAILURE);
    }

    if (pid != 0) { // Parent process
        wait(&status); // Wait for the child process to finish

        if (WIFEXITED(status)) {
            // Child process terminated normally
            sprintf(prompt, "enseash [exit:%d] %% ", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            // Child process terminated by a signal
            sprintf(prompt, "enseash [sig:%d] %% ", WTERMSIG(status));
        }
        write(STDOUT_FILENO, prompt, strlen(prompt));

    } else { // Child process
        execlp(cmd, cmd, NULL); // Execute the command
        perror("Command not found \n");
        exit(EXIT_FAILURE);
    }
}