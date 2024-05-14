#ifndef STRUCTSOLONG_H
# define STRUCTSOLONG_H

#define NUM_COLLECTABLE 5
#define MAX_XPM 5

typedef struct s_matrix
{
    int     maxX;
    int     maxY;
    char    **map;
    int     c;
    t_items p;
    t_items e;
    t_items f;
    t_items n;
    t_wmlx  mlx;
} t_matrix;

typedef struct s_img
{
	void	*wall;
	void	*flor;
	void	*coin;
	void	*exit;
	void	*nemico;
	void	*player;
	int 	width;
	int		height;
} t_img;

typedef struct s_wmlx
{
    void    *wind;
    void    *mlx;
} t_wmlx;

typedef struct  s_items
{
    void    *img;
    char    nitems;
    int     xmap;
    int     ymap;
} t_items;

#endif