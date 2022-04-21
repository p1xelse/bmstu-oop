#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "point.h"

typedef struct
{
    int dx;
    int dy;
    int dz;
} move_data_t;

typedef struct
{
    double kx;
    double ky;
    double kz;

    point_t center;
} scale_data_t;

typedef struct
{
    int ox;
    int oy;
    int oz;

    point_t center;
} turn_data_t;

void move_point(point_t& dot, move_data_t coeff);
int move_points_array(point_t* pts, int count, move_data_t coeff);

void scale_point(point_t& dot, scale_data_t coeff, point_t center);
int scale_points_array(point_t* pts, int count, scale_data_t coeff);

double d_cos(double angle);
double d_sin(double angle);

void turn_point_coord_x(point_t& dot, double angle, point_t center);
void turn_point_coord_y(point_t& dot, double angle, point_t center);
void turn_point_coord_z(point_t& dot, double angle, point_t center);
int turn_points_array(point_t* pts, int count, turn_data_t coeff);

#endif // OPERATIONS_H
