#ifndef EDGES_H
#define EDGES_H

#include <cstdio>
#include "error_handler.h"

typedef struct
{
    int numOfPoint1;
    int numOfPoint2;
} edge_t;

typedef struct
{
    int count;
    edge_t *arr;
} edges_data_t;

int edges_alloc(edges_data_t &edges, int count);
void edges_free(edges_data_t &edges);
int read_edge(edge_t* edge, FILE* f);
int read_edges_arr(edge_t* arr, int count, FILE *f);
int process_edges(edges_data_t& edges, FILE* f);
edge_t* get_edges_arr(edges_data_t& edges);
void edges_data_init(edges_data_t &data);

#endif // EDGES_H
