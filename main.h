#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/signal.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PROMPT_SIZE 64
#define WELCOME_MESSAGE "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define EXIT_MESSAGE "Bye bye ...\n"
#define PROMPT "enseash % "
#define ERR_COMMAND_MSG "Command not found! \n"
#define ERR_FORK_MSG "Fork error. \n"
#define ARG_MAX 10

void exeCommand(char *command, char *args[]);
int getCommand(char *buffer, char *argv[]);
void redirections(char *command, char *args[]);


