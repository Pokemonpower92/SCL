#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


int main(int argc, char **argv) {
    list *l = new_list();
    char *line;
    size_t len;

    while(getline(&line, &len, stdin) != -1) {
        printf("%s", line);
        push_back(l, (void *)line);
    }

    clear(l);

    while(l->size != 0) {
        char *value = (char *)pop_front(l);
        printf("%s\n", value);
    }

    free_list(l);

    return 0;
}