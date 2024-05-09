#ifndef STRUCTSOLONG_H
# define STRUCTSOLONG_H

#define NUM_COLLECTABLE 5
#define MAX_XPM 5

typedef struct s_matrix
{
   // t_map   map;
    int     maxX;
    int     maxY;
    char    **map;
    int     c;
    t_items p;
    t_items e;
    t_items f;
    t_items n;
} t_matrix;

typedef struct  s_items
{
    void    *img;
    char    nitems;
    int     xmap;
    int     ymap;
} t_items;

#endif