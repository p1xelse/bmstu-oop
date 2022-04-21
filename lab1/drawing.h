#ifndef DRAWING_H
#define DRAWING_H
#include "QGraphicsView"
#include "graph_scene.h"
#include "point.h"
#include "edges.h"

typedef struct
{
    QGraphicsView *gView;
    int width;
    int height;
} draw_data_t;

struct coord_point
{
    int x;
    int y;
};

coord_point get_dot(point_t* arr, int index);
coord_point point_transform(coord_point dot, draw_data_t draw_data);
void draw_edges(points_data_t pts, edges_data_t links, draw_data_t arg, graph_scene_t gr_scene);
void draw_line(coord_point p1, coord_point p2, graph_scene_t a, draw_data_t arg);

#endif // DRAWING_H
