#ifndef EDGES_LINKS_CPP
#define EDGES_LINKS_CPP

#include <cstdlib>
#include "edges.h"
#include "figure.h"
#include "error_handler.h"
#include "input.h"

int edges_alloc(edges_data_t &edges, int count)
{
    edges.count = count;

    edges.arr = (edge_t*) calloc(count, sizeof(edge_t));
    if (!edges.arr)
        return ERR_ALLOCATE;

    return NONE;
}
void edges_free(edges_data_t &edges)
{
    if (edges.arr)
        free(edges.arr);
}
int read_edge(edge_t* edge, FILE* f)
{
    if (fscanf(f, "%d%d", &edge->numOfPoint1, &edge->numOfPoint2) != 2)
        return ERR_FILE_FORMAT;

    return NONE;
}
int read_edges_arr(edge_t* arr, int count, FILE *f)
{
    int err = NONE;
    for (int i = 0; i < count && !err; i++)
    {
        if (read_edge(&arr[i], f))
            err = ERR_FILE_FORMAT;
    }

    return err;
}

edge_t* get_edges_arr(edges_data_t& edges)
{
    return edges.arr;
}

int process_edges(edges_data_t& edges, FILE* f)
{
    int count;
    int err = NONE;

    err = read_count(&count, f);
    if (!err)
    {
        if (count)
            err = edges_alloc(edges, count);
        else
            err = ERR_NO_EDGES;

        if (!err)
        {
            if ((err = read_edges_arr(edges.arr, count, f)) == ERR_FILE_FORMAT)
                edges_free(edges);
        }
    }
    return err;
}

void edges_data_init(edges_data_t &data)
{
    data.arr = NULL;
    data.count = 0;
}


#endif // EDGES_LINKS_CPP
