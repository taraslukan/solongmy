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
} t_matrix;

#endif