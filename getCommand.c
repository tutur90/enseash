#include "main.h"

// Function to read and parse user input
void getCommand(char *buffer, char *argv[]) {
    int command_size = read(0, buffer, BUFFER_SIZE);
    buffer[command_size - 1] = '\0';

    if (buffer[command_size - 1] == '\n') {
        buffer[command_size - 1] = '\0';
    } else {
        buffer[command_size] = '\0';
    }

    int argc = 0;
    char *token = strtok(buffer, " ");
    while (token != NULL && argc < 10) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;
}
