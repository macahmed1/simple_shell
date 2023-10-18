#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int is_integer(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

