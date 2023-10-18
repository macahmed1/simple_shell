#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

void display_prompt() {
    printf("($) ");
}

char *read_input() {
    char *input = NULL;
    size_t bufsize = 0;
    ssize_t num_chars = getline(&input, &bufsize, stdin);

    if (num_chars == -1) {
        if (input) {
            free(input);
        }
        return NULL;
    }

    input[num_chars - 1] = '\0';
    return input;
}

/*
char *find_command_path(char *command) {
    return NULL;
}

void execute_command(char *command, char *args) {
}
*/
