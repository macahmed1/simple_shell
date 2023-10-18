#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream) {
    char *line = *lineptr;
    ssize_t ch;
    ssize_t read_chars = 0;
    size_t size;

    if (line == NULL) {
        *n = 0;
        return -1;
    }

    size = *n;

    while (1) {
        ch = fgetc(stream);

        if (ch == EOF || ch == '\n') {
            if (ch == EOF && read_chars == 0) {
                return -1;
            }
            if (line == NULL || size == 0) {
                *lineptr = NULL;
                *n = 0;
            }
            return read_chars;
        }

	if ((size_t)read_chars >= size) {

            size = (size == 0) ? 1 : size * 2;
          char *new_line = (char *)realloc(line, size);
            if (new_line == NULL) {
                return -1;
            }
            line = new_line;
            *lineptr = line;
            *n = size;
        }

        line[read_chars++] = (char)ch;
    }
}


ssize_t (char *input, size_t bufsize) {

    char *input = NULL;
    size_t bufsize = 0;

    while (1) {
        display_prompt();
        ssize_t num_chars = _getline(&input, &bufsize, stdin);

        if (num_chars == -1) {
            break;
        }

    }

    free(input);
    return 0;
}

