#ifndef GRAPH_SCENE_H
#define GRAPH_SCENE_H

#include "QGraphicsView"

typedef struct
{
    QGraphicsScene *scene;
    QPen pen;
} graph_scene_t;

int init_graph_scene(graph_scene_t &gr_scene, QGraphicsView *gView);
void del_graph_scene(graph_scene_t &gr_scene);
void set_graph_scene(QGraphicsView *gView, graph_scene_t &gr_scene);

#endif // GRAPH_SCENE_H
