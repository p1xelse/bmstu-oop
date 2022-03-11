#include "action_handler.h"
#include "error_handler.h"
#include "operations.h"
#include "figure.h"


file_data_t get_file_data(action_t act)
{
    return act.file_data;
}

int action_handler(action_t act)
{
    static figure_t fig = init();
    int err = NONE;

    switch (act.type)
    {
    case NO_ACTION:
        break;
    case LOAD_FILE:
        err = load_figure_from_file(fig, get_file_data(act).filename); //
        break;
    case DRAW:
        err = draw_figure(fig, act.draw_data);
        break;
    case MOVE:
        err = move_figure(fig, act.move_data);
        break;
    case SCALE:
        err = scale_figure(fig, act.scale_data);
        break;
    case TURN:
        err = turn_figure(fig, act.turn_data);
        break;
    case QUIT:
        empty_figure(fig);
        break;
    default:
        err = ERR_UNKNOWN_COMMAND;
    }

    return err;
}

