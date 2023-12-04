#include "main.h"

// Function to read and parse user input
int getCommand(char *buffer, char *argv[]) {
    int command_size = read(0, buffer, BUFFER_SIZE);
    buffer[command_size - 1] = '\0';

    int argc = 0;
    char *token = strtok(buffer, " ");
    while (token != NULL && argc < ARG_MAX) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;
    return command_size;
}
