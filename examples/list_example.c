#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


int main(int argc, char **argv) {
    list *l = new_list();
    list *b;
    char *line;
    size_t len;

    while(getline(&line, &len, stdin) != -1) {
        push_back(l, (void *)strdup(line));
    }

    while(l->size != 0) {
        printf("%s", (char *)pop_back(l));
    }

    return 0;
}