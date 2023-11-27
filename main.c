#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define WELCOME_MESSAGE "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define EXIT_MESSAGE "Bye bye ...\n"
#define PROMPT "enseash %"



int main() {

    char buffer[BUFFER_SIZE];
    write(1, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));

    while(1) {
        write(1, PROMPT, strlen(PROMPT));
        int command_size = read(0, buffer, BUFFER_SIZE);
        buffer[command_size - 1] = '\0';

        int response = exeCommand(buffer, command_size);
        if (response == -1) {
            write(1, "Commande introuvable.\n", strlen("Commande introuvable.\n"));
        }

//        if (strcmp(buffer, "exit") == 0) {
//            write(1, EXIT_MESSAGE, strlen(EXIT_MESSAGE));
//
//            break;
//        }
    }
    return 0;
}

//int exeCommand(char *command, int command_size) {
//    int pid = fork();
//    if (pid == 0) {
//        // Child process
//        execlp(command, command, NULL);
//    } else {
//        // Parent process
//        wait(NULL);
//    }
//    return 0;
//}
