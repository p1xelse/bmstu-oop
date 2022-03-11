#include "cstdio"
#include <cstdlib>
#include "figure.h"
#include "error_handler.h"
#include "point.h"
#include "edges.h"
#include "drawing.h"
#include "graph_scene.h"
#include "operations.h"

figure_t& init()
{
    static figure_t figure;

    points_data_init(figure.points);
    edges_data_init(figure.edges);

    return figure;
}

void empty_figure(figure_t& fig)
{
    fig.points.count = 0;
    points_free(fig.points);

    fig.edges.count = 0;
    edges_free(fig.edges);
}

void copy_figure(figure_t& figure_dst, figure_t& figure_src)
{
    figure_dst = figure_src;
//    figure_dst.points.count = figure_src.points.count; //
//    figure_dst.points.arr = figure_src.points.arr; //

//    figure_dst.edges.count = figure_src.edges.count; //
//    figure_dst.edges.arr = figure_src.edges.arr; //
}

int load_figure_from_file(figure_t& fig, const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return ERR_FILE_NOT_FOUND;
    figure_t fig_tmp = init();

    int err = process_points(fig_tmp.points, f);
    if (!err) // уровень абстракции, фигура - точка
    {
        err = process_edges(fig_tmp.edges, f);
        if (err != NONE)
            points_free(fig_tmp.points);
    }

    fclose(f);

    if (!err)
    {
        empty_figure(fig);
        copy_figure(fig, fig_tmp);
    }

    return err;
}


int draw_figure(figure_t fig, draw_data_t draw_data)
{
    graph_scene_t a;

    int err = init_graph_scene(a, draw_data.gView);
    if (err)
        return err;

    draw_edges(fig.points, fig.edges, draw_data, a);

    a.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(draw_data.width, draw_data.height))); //
    set_graph_scene(draw_data.gView, a);

    return err;
}

int move_figure(figure_t& fig, move_data_t coeff)
{
    return move_points_array(fig.points.arr, fig.points.count, coeff);
}

int scale_figure(figure_t& fig, scale_data_t coeff)
{
    return scale_points_array(fig.points.arr, fig.points.count, coeff);
}

int turn_figure(figure_t& fig, turn_data_t coeff)
{
    return turn_points_array(fig.points.arr, fig.points.count, coeff);
}
