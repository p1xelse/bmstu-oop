#include "graph_scene.h"
#include "error_handler.h"

int init_graph_scene(graph_scene_t &gr_scene, QGraphicsView *gView)
{
    gr_scene.scene = new QGraphicsScene(gView);
    if (!gr_scene.scene)
        return ERR_ALLOCATE;

    gr_scene.pen = QPen(Qt::black);

    return NONE;
}

void del_graph_scene(graph_scene_t &gr_scene)
{
    delete gr_scene.scene;
}

void set_graph_scene(QGraphicsView *gView, graph_scene_t &gr_scene)
{
    QGraphicsScene *prev = gView->scene();
    delete prev;
    gView->setScene(gr_scene.scene);
}

void set_scene_rect(graph_scene_t &gr_scene, int width, int height)
{
    gr_scene.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(width, height)));
}
