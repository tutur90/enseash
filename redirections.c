#include "main.h"


void redirections(char *cmd, char* tokens[]) {

    char* input_file = NULL;
    char* output_file = NULL;

    char* args[ARG_MAX];

    int i = 0;
    
    while (tokens[i] != NULL) {
        // Check for input redirection
        if (strcmp(tokens[i], "<") == 0) {

            input_file = tokens[i+1];
        }
        // Check for output redirection
        else if (strcmp(tokens[i], ">") == 0) {
            output_file = tokens[i+1];
        }
        // Collect command and arguments
        else {
            args[i] = tokens[i];
        }
        i++;
    }

    // Null-terminate the tokens array
    args[i] = NULL;

    // Perform input redirection if specified
    if (input_file != NULL) {

        int in = open(input_file, O_RDONLY);
        if (in == -1) {
            perror("Error opening input file");
            exit(EXIT_FAILURE);
        }
        dup2(in, STDIN_FILENO);
        close(in);
    }

    // Perform output redirection if specified
    if (output_file != NULL) {
        int out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (out == -1) {
            perror("Error opening output file");
            exit(EXIT_FAILURE);
        }
        dup2(out, STDOUT_FILENO);
        close(out);
    }

    // Execute the command
    if (execvp(cmd, args) == -1) {
        perror("Execution failed");
        exit(EXIT_FAILURE);
    }
}
