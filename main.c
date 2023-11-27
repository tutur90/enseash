#include "main.h"




int main() {

    char buffer[BUFFER_SIZE];
    char *argv[10]; // Command-line arguments

    write(1, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));
    write(1, PROMPT, strlen(PROMPT));

    while(1) {
        getCommand(buffer, argv); // Read and parse user input
        if (strcmp(buffer,"exit") == 0){
            write(1, EXIT_MESSAGE, strlen(EXIT_MESSAGE));
            break;
        }
        exeCommand(buffer, argv); // Execute the command
    }
    exit(EXIT_SUCCESS);
}