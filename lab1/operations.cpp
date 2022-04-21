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


void scale_point(point_t& dot, scale_data_t coeff, point_t center)
{
    dot.x *= coeff.kx;
    dot.y *= coeff.ky;
    dot.z *= coeff.kz;

    dot.x = coeff.kx * dot.x + (1 - coeff.kx) * center.x;
    dot.y = coeff.ky * dot.y + (1 - coeff.ky) * center.y;
    dot.z = coeff.kz * dot.z + (1 - coeff.kz) * center.z;
}

int scale_points_array(point_t* pts, int count, scale_data_t coeff)
{
    if(!pts)
        return ERR_NO_POINTS;
    int err = 0;

    point_t center = coeff.center;
    for(int i = 0; i < count; i++)
        scale_point(pts[i], coeff, center);

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

void move_point_to_init_state(point_t &point, const point_t &center)
{
    move_data_t init_move;
    init_move.dx = -center.x;
    init_move.dy = -center.y;
    init_move.dz = -center.z;
    move_point(point, init_move);
}

void move_point_to_center(point_t &point, const point_t &center)
{
    move_data_t center_move;
    center_move.dx = center.x;
    center_move.dy = center.y;
    center_move.dz = center.z;
    move_point(point, center_move);
}

void turn_point_coord_x(point_t& dot, double angle, point_t center)
{
    move_point_to_init_state(dot, center);

    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    double tmp_y = dot.y;
    dot.y = dot.y * cos_ang - dot.z * sin_ang;
    dot.z = tmp_y * sin_ang + dot.z * cos_ang;

    move_point_to_center(dot, center);
}

void turn_point_coord_y(point_t& dot, double angle, point_t center)
{
    move_point_to_init_state(dot, center);

    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    double tmp_x = dot.x;
    dot.x = dot.x * cos_ang + dot.z * sin_ang;
    dot.z = -tmp_x * sin_ang + dot.z * cos_ang;

    move_point_to_center(dot, center);
}

void turn_point_coord_z(point_t& dot, double angle, point_t center)
{
    move_point_to_init_state(dot, center);

    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    double tmp_x = dot.x;

    dot.x = dot.x * cos_ang - dot.y * sin_ang;
    dot.y = tmp_x * sin_ang + dot.y * cos_ang;

    move_point_to_center(dot, center);
}


int turn_points_array(point_t* pts, int n, turn_data_t coeff)
{
    if(!pts)
        return ERR_NO_POINTS;

    int err = 0;

    point_t center = coeff.center;
    for(int i = 0; i < n; i++)
    {
        turn_point_coord_x(pts[i], coeff.ox, center);
        turn_point_coord_y(pts[i], coeff.oy, center);
        turn_point_coord_z(pts[i], coeff.oz, center);
    }

    return err;
}
