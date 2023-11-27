#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE]="Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\nenseash %";
    write(1, buffer, strlen(buffer));
//    while(1) {
//        char buffer[BUFFER_SIZE];
//        int n = read(0, buffer, BUFFER_SIZE);
//        if (n == 0) {
//            break;
//        }
//        if (buffer =='exit') {
//            printf("Au revoir !\n");
//            break;
//        }
//        write(1, buffer, n);
//
//    }
    return 0;
}
