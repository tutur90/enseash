#include "main.h"

char prompt[PROMPT_SIZE];

struct timespec start, stop;
double timer;

void exeCommand(char *cmd, char* args[]) {

    pid_t pid;
    int status;

    // Start timer
    clock_gettime(CLOCK_MONOTONIC, &start);

    pid = fork();

    if (pid == -1) {
        perror("Fork error \n");
        exit(EXIT_FAILURE);
    } else if (pid != 0) { // Parent process
        wait(&status); // Wait for the child process to finish

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

    } else { // Child process
    if (execlp(cmd, cmd, args[1], args[2], NULL) == -1) // Execute the command
        {
            perror(ERR_COMMAND_MSG);
            exit(EXIT_FAILURE);
        }
    }
}