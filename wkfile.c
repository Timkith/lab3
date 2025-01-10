#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void append_stack_rows_to_file(const char *filename, obj *top)
{
    FILE *file = fopen("result", "w");
    obj *current = top;
    while (current != NULL)
    {
        fprintf(file, "%d ", current->data);
        current = current->next;
    }
    fprintf(file, "\n");

    fclose(file);
}