#include <cstdio>
#include "input.h"
#include "error_handler.h"

int read_count(int* count, FILE* f)
{
    int err = 0;

    if (fscanf(f, "%d", count) != 1)
        err = ERR_FILE_FORMAT;

    if (*count <= 0)
        err = ERR_FILE_CONTENT;

    return err;
}
