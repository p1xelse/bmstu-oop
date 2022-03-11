#ifndef FIGURE_H
#define FIGURE_H
#include "point.h"
#include "edges.h"
#include "drawing.h"
#include "operations.h"
#include "error_handler.h"

typedef struct
{
    points_data_t points;
    edges_data_t edges;
} figure_t;

figure_t& init();
void empty_figure(figure_t& fig);
void copy_figure(figure_t& figure_dst, figure_t& figure_src);
int load_figure_from_file(figure_t &fig, const char *filename);

int draw_figure(figure_t fig, draw_data_t draw_data);

int move_figure(figure_t& fig, move_data_t coeff);
int scale_figure(figure_t& fig, scale_data_t coeff);
int turn_figure(figure_t& fig, turn_data_t coeff);

#endif // FIGURE_H
