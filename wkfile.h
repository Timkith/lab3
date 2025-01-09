#ifndef wkfile_h
#define wkfile_h
#include "stack.h"

#define mx_lengh 256

void print_last_two_lines(const char *filename);
void append_stack_rows_to_file(const char *filename, obj *stack);

#endif
