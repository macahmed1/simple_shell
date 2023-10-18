#include <stddef.h>
#include <stdio.h>
#ifndef SHELL_H
#define SHELL_H

/* Function prototypes for input.c */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* Function prototypes for execution.c */
char *find_command_path(char *command);

/* Function prototypes for parsing.c */
void split_input(char *input, char **command, char ***arguments, int *num_args);

/* Function prototypes for builtin.c */
void handle_builtin_exit(char **arguments, int num_args);
void handle_builtin_env();
void handle_builtin_setenv(char **arguments, int num_args);
void handle_builtin_unsetenv(char **arguments, int num_args);
void handle_builtin_cd(char **arguments, int num_args);
void handle_builtin_alias(char **arguments, int num_args);
void handle_builtin_variables(char *input);
void handle_builtin_comments(char *input);

/* Function prototypes for main.c */
/* int main(int argc, char *argv[]); */
int main(void);
#endif

