#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"

int main()
{
    char *input = NULL;
    size_t bufsize = 0;


    while (1) {
        ssize_t num_chars = _getline(&input, &bufsize, stdin);

        if (num_chars == -1) {
            break;
        }

    	char *command = strtok(input, " \n");

        while (command != NULL) {
            pid_t child_pid = fork();

            if (child_pid == -1) {
                perror("fork");
                exit(1);
            }

            if (child_pid == 0) {

              char *args[] = {command, NULL};
                if (execvp(command, args) == -1) {
                    perror("execvp");
                    exit(1);
                }
            } else {
                wait(NULL);
            }

            command = strtok(NULL, " \n");
        }
    }

    free(input);
    return 0;
}

