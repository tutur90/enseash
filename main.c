#include "exeCommand.h"



int main() {
    char buffer[BUFFER_SIZE];
    char prompt[PROMPT_SIZE] = PROMPT;
   
    write(1, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE)); // Print welcome message

    write(1, PROMPT, strlen(PROMPT)); // Print the initial prompt
    while(1) {
        int command_size = read(0, buffer, BUFFER_SIZE); // Read user input
        buffer[command_size - 1] = '\0'; // Replace newline character with null terminator

        if (strcmp(buffer,"exit") == 0 || command_size == 0){
            write(1, EXIT_MESSAGE, strlen(EXIT_MESSAGE)); // Print exit message
            break;
        }
        exeCommand(buffer); // Execute the command
    }
    exit(EXIT_SUCCESS);
}
