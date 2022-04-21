#ifndef POINT_H
#define POINT_H

#include <cstdio>
#include "error_handler.h"

typedef struct
{
    double x;
    double y;
    double z;
} point_t;

typedef struct
{
    int count;
    point_t* arr;
} points_data_t;

int points_alloc(points_data_t& pts, int count);
void points_free(points_data_t& pts);

int read_point(point_t* point, FILE* f);
int read_points_arr(point_t *arr, int n, FILE *f);
int process_points(points_data_t &pts, FILE *f);
void points_data_init(points_data_t &data);

#endif // POINT_H
