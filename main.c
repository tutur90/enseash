#include "main.h"

int main() {
    char buffer[BUFFER_SIZE];
    char prompt[PROMPT_SIZE] = PROMPT;
   
    write(1, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));

    write(1, PROMPT, strlen(PROMPT));
    while(1) {
        int command_size = read(0, buffer, BUFFER_SIZE);
        buffer[command_size - 1] = '\0';

        if (strcmp(buffer,"exit") == 0){
            write(1, EXIT_MESSAGE, strlen(EXIT_MESSAGE));
            break;
        }
        exeCommand(buffer, NULL);
    }
    exit(EXIT_SUCCESS);
}