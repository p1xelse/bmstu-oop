#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

enum errors
{
    NONE,
    ERR_FILE_NOT_FOUND,
    ERR_FILE_FORMAT,
    ERR_FILE_CONTENT,
    ERR_ALLOCATE,
    ERR_NO_POINTS,
    ERR_NO_EDGES,
    ERR_UNKNOWN_COMMAND
};

void display_error_message(errors err);

#endif // ERROR_HANDLER_H
