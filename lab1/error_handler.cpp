#include "error_handler.h"
#include "QMessageBox"
#include <QObject>

void display_error_message(errors err)
{
    if (err == ERR_FILE_NOT_FOUND)
    {
        QMessageBox::critical(NULL, "ERROR", "File is broken, or doesn't exist");
    }
    else if (err == ERR_FILE_FORMAT)
    {
        QMessageBox::critical(NULL, "ERROR", "File format error");
    }
    else if (err == ERR_FILE_CONTENT)
    {
        QMessageBox::critical(NULL, "ERROR", "File has wrong content");
    }
    else if (err == ERR_ALLOCATE)
    {
        QMessageBox::critical(NULL, "ERROR", "Error with memory allocation");
    }
    else if (err == ERR_NO_POINTS)
    {
        QMessageBox::critical(NULL, "ERROR", "File is empty, or array is empty!");
    }
    else if (err == ERR_UNKNOWN_COMMAND)
    {
        QMessageBox::critical(NULL, "ERROR", "Unknown command in enter point!");
    }
    else
    {
        QMessageBox::critical(NULL, "ERROR", "Unknown error");
    }
}
