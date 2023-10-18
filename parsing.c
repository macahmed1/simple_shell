#include <string.h>
#include "shell.h"
#include <stdlib.h>

/* Implement functions for parsing input */
int main()
{
	int MAX_INPUT_SIZE;

	char input[MAX_INPUT_SIZE];  /* Declare and initialize input */
    /* Read input from the user or another source into the input variable */

    /* Task 11 (;): Implement code for handling command separators ;. */
    /* Inside the while loop */
    char *token = strtok(input, ";");
    while (token != NULL) {
        char *command;
        char **arguments;
        int num_args;
        split_input(token, &command, &arguments, &num_args);

        /* Execute the command as needed */

        free(arguments);
        token = strtok(NULL, ";");
    }

    /* Task 12 (&& and ||): Implement code for handling logical operators && and ||. */
    /* Inside the while loop */
    int success = 1;
    token = strtok(input, "&&"); /* Reusing the token variable */ 

	while (token != NULL) {
        char *command;
        char **arguments;
        int num_args;
        split_input(token, &command, &arguments, &num_args);

        /* Execute the command as needed */

        if (success && exec_successfully) {
            success = 1;
        } else {
            success = 0;
        }

        free(arguments);
        token = strtok(NULL, "&&");
    }

    /* Task 15 (Comments): Implement code to handle comments starting with #. */
    /* Inside the while loop */

	if (token[0] == '#') {
    token = strtok(NULL, "&&");  // Move to the next token
    continue;
}

      /*  if (input[0] == '#') {
        continue;
    }
  */
    return 0;
}

