/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movepl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:41:35 by tlukan            #+#    #+#             */
/*   Updated: 2024/05/22 14:28:25 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	m_right(t_matrix *map)
{
	int	playerx;
	int	playery;

	playerx = map->p.xmap;
	playery = map->p.ymap;
	if (map->map[playery][playerx + 1] == 'E')
	{
		if (map->c == 0)
		{
			ft_putstr("\nHai vinto! Ma Tarallo spacca!\n");
			exit(1);
		}
	}
	else if (map->map[playery][playerx + 1] != '1')
	{
		if (map->map[playery][playerx + 1] == 'C')
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

void	m_left(t_matrix *map)
{
	int	playerx;
	int	playery;

	playerx = map->p.xmap;
	playery = map->p.ymap;
	if (map->map[playery][playerx - 1] == 'E')
	{
		if (map->c == 0)
		{
			ft_putstr("\nHai vinto! Ma Tarallo spacca!\n");
			exit(1);
		}
	}
	else if (map->map[playery][playerx - 1] != '1')
	{
		if (map->map[playery][playerx - 1] == 'C')
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

void	m_up(t_matrix *map)
{
	int	playerx;
	int	playery;

	playerx = map->p.xmap;
	playery = map->p.ymap;
	if (map->map[playery - 1][playerx] == 'E')
	{
		if (map->c == 0)
		{
			ft_putstr("\nHai vinto! Ma Tarallo spacca!\n");
			ezzit(map);
		}
	}
	else if (map->map[playery - 1][playerx] != '1')
	{
		if (map->map[playery - 1][playerx] == 'C')
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

void	m_down(t_matrix *map)
{
	int	playerx;
	int	playery;

	playerx = map->p.xmap;
	playery = map->p.ymap;
	if (map->map[playery + 1][playerx] == 'E')
	{
		if (map->c == 0)
		{
			ft_putstr("\nHai vinto! Ma Tarallo spacca!\n");
			exit(1);
		}
	}
	else if (map->map[playery + 1][playerx] != '1')
	{
		if (map->map[playery + 1][playerx] == 'C')
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

int	window_escape(t_matrix *map)
{
	mlx_destroy_window(map->mlx.mlx, map->mlx.wind);
	del_clone(map->map);
	exit(1);
	return (1);
}
