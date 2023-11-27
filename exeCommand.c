#include "main.h"

char prompt[PROMPT_SIZE];

struct timespec start, stop;
double timer;

// Function to execute a command with timing information
void exeCommand(char *cmd, char* args[]) {
    pid_t pid;
    int status;

    // Start timer
    clock_gettime(CLOCK_MONOTONIC, &start);

    pid = fork();

    if (pid == -1) {
        perror("Fork error \n");
        exit(EXIT_FAILURE);
    }

    if (pid != 0) {
        wait(&status);

        // Stop timer
        clock_gettime(CLOCK_MONOTONIC, &stop);
        timer = (stop.tv_sec - start.tv_sec) * 1000000.0 + (stop.tv_nsec - start.tv_nsec) / 1000.0;

        if (WIFEXITED(status)) {
            // Child process terminated normally
            sprintf(prompt, "enseash [exit:%d | %f ms] %% ", WEXITSTATUS(status), timer);
        } else if (WIFSIGNALED(status)) {
            // Child process terminated by a signal
            sprintf(prompt, "enseash [sig:%d | %f ms] %% ", WTERMSIG(status), timer);
        }
        write(STDOUT_FILENO, prompt, strlen(prompt));

    } else {
        execlp(cmd, cmd, args, NULL);

        perror("Command not found \n");
        exit(EXIT_FAILURE);
    }
}
