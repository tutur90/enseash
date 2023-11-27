#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define FILE_DESCRIPTION 0


int main() {
    char buffer[BUFFER_SIZE]="Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\nenseash %";
    write(FILE_DESCRIPTION, buffer, strlen(buffer));

    return 0;
}
