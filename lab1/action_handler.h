#ifndef ACTION_HANDLER_H
#define ACTION_HANDLER_H

#include "drawing.h"
#include "operations.h"

enum type_action
{
    NO_ACTION,
    LOAD_FILE,
    DRAW,
    MOVE,
    SCALE,
    TURN,
    QUIT
};

typedef struct
{
    const char* filename;
} file_data_t;

typedef struct
{
    type_action type;
    union
    {
        file_data_t file_data;
        draw_data_t draw_data;
        move_data_t move_data;
        scale_data_t scale_data;
        turn_data_t turn_data;
    };
} action_t;

int action_handler(action_t act);
file_data_t get_file_data(action_t act);

#endif // ACTION_HANDLER_H
