#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define WELCOME_MESSAGE "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"



int main() {

    char buffer[BUFFER_SIZE];
    write(1, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));


    return 0;
}
