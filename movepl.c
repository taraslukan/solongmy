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
		buildMap(map);
	}
}

void m_left(t_matrix *map)
{
    playerx = map->p.xmap;
	playery = map->p.ymap;
	if (map->map[playery][playerx - 1] != '1')
	{
		map->map[playery][playerx] = '0';
        map->map[playery][playerx - 1] = 'P';
		map->p.xmap = playerx - 1;
		map->p.ymap = playery;
		buildMap(map);
	}
	}
}

void m_up(t_matrix *map)
{
    int playerx = map->map.entry.x_axis;
	int playery = map->map.entry.y_axis;

	if (map->map[playery - 1][playerx] != '1')
	{
		map->map[playery][playerx] = '0';
        map->map[playery - 1][playerx ] = 'P';
		map->map.entry.x_axis = playerx;
		map->map.entry.y_axis = playery - 1;
		buildMap(map);
	}	
}

void m_down(t_matrix *map)
{
    int playerx = map->map.entry.x_axis;
	int playery = map->map.entry.y_axis;

	if (map->map[playery + 1][playerx] != '1')
	{
		map->map[playery][playerx] = '0';
        map->map[playery + 1][playerx ] = 'P';
		map->map.entry.x_axis = playerx;
		map->map.entry.y_axis = playery + 1;
		buildMap(map);
	}
}
int window_escape(t_start *map)
{
    mlx_destroy_window(map->mlx.mlx, map->mlx.win);
    exit(1);
    return(1);
}
