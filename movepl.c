#include "solong.h"

void m_right(t_matrix *map)
{
    int playerx;
	int playery;

	playerx = map->p.xmap;
	playery = map->p.ymap;
	if(map->map[playery][playerx + 1] == 'E')
	{
		if(map->c == 0)
		{
			ft_putstr("\nHai vinto! Ma Tarallo spacca!\n");
			exit(1);
		}
	}	
	else if (map->map[playery][playerx + 1] != '1')
	{
		if(map->map[playery][playerx + 1] == 'C')
			map->c--;
		map->map[playery][playerx] = '0';
        map->map[playery][playerx + 1] = 'P';
		map->p.xmap = playerx + 1;
		map->p.ymap = playery;
		if (map->n.xmap == map->p.xmap && map->n.ymap == map->p.ymap)
			return (ezzit(map));
		creatmap(map);
	}
}

void m_left(t_matrix *map)
{
	int playerx;
	int playery;

	playerx = map->p.xmap;
	playery = map->p.ymap;
	if(map->map[playery][playerx - 1] == 'E')
	{
		if(map->c == 0)
		{
			ft_putstr("\nHai vinto! Ma Tarallo spacca!\n");
			exit(1);
		}
	}	
	else if (map->map[playery][playerx - 1] != '1')
	{
		if(map->map[playery][playerx - 1] == 'C')
			map->c--;
		map->map[playery][playerx] = '0';
        map->map[playery][playerx - 1] = 'P';
		map->p.xmap = playerx - 1;
		map->p.ymap = playery;
		if (map->n.xmap == map->p.xmap && map->n.ymap == map->p.ymap)
			return (ezzit(map));
		creatmap(map);
	}
}

void m_up(t_matrix *map)
{
    int playerx;
	int playery;

	playerx = map->p.xmap;
	playery = map->p.ymap;
	if(map->map[playery - 1][playerx] == 'E')
	{
		if(map->c == 0)
		{
			ft_putstr("\nHai vinto! Ma Tarallo spacca!\n");
			ezzit(map);
		}
	}	
	else if (map->map[playery - 1][playerx] != '1')
	{
		if(map->map[playery - 1][playerx] == 'C')
			map->c--;
		map->map[playery][playerx] = '0';
        map->map[playery - 1][playerx] = 'P';
		map->p.xmap = playerx;
		map->p.ymap = playery - 1;
		if (map->n.xmap == map->p.xmap && map->n.ymap == map->p.ymap)
			return (ezzit(map));
		creatmap(map);
	}
}

void m_down(t_matrix *map)
{
    int playerx;
	int playery;

	playerx = map->p.xmap;
	playery = map->p.ymap;
	if(map->map[playery + 1][playerx] == 'E')
	{
		if(map->c == 0)
			{
				ft_putstr("\nHai vinto! Ma Tarallo spacca!\n");
				exit(1);
			}	
	}
	else if (map->map[playery + 1][playerx] != '1')
	{
		if(map->map[playery + 1][playerx] == 'C')
			map->c--;
		map->map[playery][playerx] = '0';
        map->map[playery + 1][playerx] = 'P';
		map->p.xmap = playerx;
		map->p.ymap = playery + 1;
		if (map->n.xmap == map->p.xmap && map->n.ymap == map->p.ymap)
			return (ezzit(map));
		creatmap(map);
	}
}

int window_escape(t_matrix *map)
{
    mlx_destroy_window(map->mlx.mlx, map->mlx.wind);
		del_clone(map->map);
	free(map->img.wall);
	free(map->img.flor);
	free(map->img.coin1);
	free(map->img.coin2);
	free(map->img.coin3);
	free(map->img.coin4);
	free(map->img.coin5);
	free(map->img.exit);
	free(map->img.nemico);
	free(map->img.player);
    exit(1);
	return (1);
}
