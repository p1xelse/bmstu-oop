#include "cstdio"
#include <cstdlib>
#include "point.h"
#include "figure.h"
#include "input.h"

int points_alloc(points_data_t& pts, int count)
{
    pts.count = count;
    pts.arr = (point_t*) calloc(count, sizeof(point_t));

    if (!pts.arr)
        return ERR_ALLOCATE;

    return NONE;
}


void points_free(points_data_t &pts)
{
    if (pts.arr)
        free(pts.arr);
}


int read_point(point_t* point, FILE* f)
{
    if (fscanf(f, "%lf%lf%lf", &point->x, &point->y, &point->z) != 3)
        return ERR_FILE_FORMAT;

    return NONE;
}


int read_points_arr(point_t *arr, int count, FILE *f)
{
    int err = NONE;
    for (int i = 0; i < count && !err; i++)
    {
        if (read_point(&arr[i], f))
            err = ERR_FILE_FORMAT;
    }
    return err;
}

void points_data_init(points_data_t &data)
{
    data.arr = NULL;
    data.count = 0;
}


int process_points(points_data_t &pts, FILE *f)
{
    int count;
    int err = NONE;

    err = read_count(&count, f);

    if (!count) //
        err = ERR_NO_POINTS;

    if (!err)
    {
        err = points_alloc(pts, count);

        if (!err)
        {
            if ((err = read_points_arr(pts.arr, count, f)) == ERR_FILE_FORMAT)
                points_free(pts);
        }
    }
    return err;
}
