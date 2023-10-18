#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

void handle_builtin_exit(char **arguments, int num_args) {
    if (strcmp(arguments[0], "exit") == 0) {
        if (num_args > 1) {
            int status = atoi(arguments[1]);
            exit(status);
        } else {
            exit(0);
        }
    }
}

void handle_builtin_env() {
}

void handle_builtin_setenv(char **arguments, int num_args) {
    if (num_args > 2) {
        if (setenv(arguments[1], arguments[2], 1) != 0) {
            perror("Setenv error");
        }
    } else {
        printf("Usage: setenv VARIABLE VALUE\n");
    }
}

void handle_builtin_unsetenv(char **arguments, int num_args) {
    if (num_args > 1) {
        if (unsetenv(arguments[1]) != 0) {
            perror("Unsetenv error");
        }
    } else {
        printf("Usage: unsetenv VARIABLE\n");
    }
}

void handle_builtin_cd(char **arguments, int num_args) {
    if (num_args > 1) {
        if (chdir(arguments[1]) != 0) {
            perror("Chdir error");
        }
    } else {
        if (chdir(getenv("HOME")) != 0) {
            perror("Chdir error");
        }
    }
}

/*
void handle_builtin_alias() {
}

void handle_builtin_variables() {
}

void handle_builtin_comments() {
}
*/
