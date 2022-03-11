#include <math.h>
#include "operations.h"
#include "error_handler.h"
#include "figure.h"

#include <iostream>

void move_point(point_t& point, move_data_t coeff)
{
    point.x += coeff.dx;
    point.y += coeff.dy;
    point.z += coeff.dz;
}

int move_points_array(point_t* pts, int count, move_data_t coeff)
{
    if(!pts)
        return ERR_NO_POINTS;

    int err = 0;

    for(int i = 0; i < count; i++)
        move_point(pts[i], coeff);

    return err;
}


void scale_point(point_t& dot, scale_data_t coeff)
{
    dot.x *= coeff.kx;
    dot.y *= coeff.ky;
    dot.z *= coeff.kz;
}

int scale_points_array(point_t* pts, int count, scale_data_t coeff)
{
    if(!pts)
        return ERR_NO_POINTS;
    int err = 0;

    for(int i = 0; i < count; i++)
        scale_point(pts[i], coeff);

    return err;
}


double d_cos(double angle)
{
    return cos(angle * 3.1415 / 180);
}

double d_sin(double angle)
{
    return sin(angle * 3.1415 / 180);
}

void turn_point_coord_x(point_t& dot, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    double tmp_y = dot.y;

    dot.y = dot.y * cos_ang + dot.z * sin_ang;
    dot.z = -tmp_y * sin_ang + dot.z * cos_ang;
}

void turn_point_coord_y(point_t& dot, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    double tmp_x = dot.x;

    dot.x = dot.x * cos_ang + dot.z * sin_ang;
    dot.z = -tmp_x * sin_ang + dot.z * cos_ang;
}

void turn_point_coord_z(point_t& dot, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    double tmp_x = dot.x;

    dot.x = dot.x * cos_ang + dot.y * sin_ang;
    dot.y = -tmp_x * sin_ang + dot.y * cos_ang;
}


int turn_points_array(point_t* pts, int n, turn_data_t coeff)
{
    if(!pts)
        return ERR_NO_POINTS;

    int err = 0;

    for(int i = 0; i < n; i++)
    {
        turn_point_coord_x(pts[i], coeff.ox);
        turn_point_coord_y(pts[i], coeff.oy);
        turn_point_coord_z(pts[i], coeff.oz);
    }

    return err;
}
