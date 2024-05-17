#include "solong.h"

void m_right(t_matrix *map)
{
    int playerx;
	int playery;

	playerx = map->p.xmap;
	playery = map->p.ymap;
	if (map->map[playery][playerx + 1] != '1')
	{
		map->map[playery][playerx] = '0';
        map->map[playery][playerx + 1] = 'P';
		map->p.xmap = playerx + 1;
		map->p.ymap = playery;
		creatmap(map);
	}
}

void m_left(t_matrix *map)
{
	int playerx;
	int playery;

	playerx = map->p.xmap;
	playery = map->p.ymap;
	if (map->map[playery][playerx - 1] != '1')
	{
		map->map[playery][playerx] = '0';
        map->map[playery][playerx - 1] = 'P';
		map->p.xmap = playerx - 1;
		map->p.ymap = playery;
		creatmap(map);
	}
}

void m_up(t_matrix *map)
{
    int playerx;
	int playery;

	playerx = map->p.xmap;
	playery = map->p.ymap;
	if (map->map[playery - 1][playerx] != '1')
	{
		map->map[playery][playerx] = '0';
        map->map[playery - 1][playerx] = 'P';
		map->p.xmap = playerx;
		map->p.ymap = playery - 1;
		creatmap(map);
	}
}

void m_down(t_matrix *map)
{
    int playerx;
	int playery;

	playerx = map->p.xmap;
	playery = map->p.ymap;
	if (map->map[playery + 1][playerx] != '1')
	{
		map->map[playery][playerx] = '0';
        map->map[playery + 1][playerx] = 'P';
		map->p.xmap = playerx;
		map->p.ymap = playery + 1;
		creatmap(map);
	}
}

int window_escape(t_matrix *map)
{
    mlx_destroy_window(map->mlx.mlx, map->mlx.wind);
    exit(1);
    return(1);
}
