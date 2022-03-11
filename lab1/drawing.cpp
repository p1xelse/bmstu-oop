#include "drawing.h"

coord_point get_dot(point_t* arr, int index)
{
    coord_point dot = {(int)arr[index].x, (int)arr[index].y};
    return dot;
}


coord_point point_transform(coord_point point, draw_data_t draw_data)
{
    coord_point tmp;

    tmp.x = point.x + draw_data.width / 2;
    tmp.y = point.y + draw_data.height / 2;

    return tmp;
}


void draw_edges(points_data_t points, edges_data_t edges, draw_data_t arg, graph_scene_t gr_scene)
{
    coord_point point1, point2;
    edge_t* edges_arr = get_edges_arr(edges);

    for (int i = 0; i < edges.count; i++)
    {
        point1 = get_dot(points.arr, edges_arr[i].numOfPoint1); //
        point2 = get_dot(points.arr, edges_arr[i].numOfPoint2); //
        draw_line(point1, point2, gr_scene, arg);
    }
}

void my_addLine(graph_scene_t gr_scene, int x1, int x2, int y1, int y2)
{
    gr_scene.scene->addLine(x1, y1, x2, y2, gr_scene.pen);
}

void draw_line(coord_point p1, coord_point p2, graph_scene_t gr_scene, draw_data_t arg)
{
    p1 = point_transform(p1, arg);
    p2 = point_transform(p2, arg);

    my_addLine(gr_scene, p1.x, p2.x, p1.y, p2.y);
}


