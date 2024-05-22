/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:39:28 by tlukan            #+#    #+#             */
/*   Updated: 2024/05/21 17:58:05 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	n_move_up(t_matrix *map, int playery, int playerx)
{
	map->map[playery][playerx] = '0';
	map->map[playery - 1][playerx] = 'N';
	map->n.xmap = playerx;
	map->n.ymap = playery - 1;
	if (map->n.xmap == map->p.xmap && map->n.ymap == map->p.ymap)
		return (ezzit(map));
	creatmap(map);
}

void	n_move_right(t_matrix *map, int playery, int playerx)
{
	map->map[playery][playerx] = '0';
	map->map[playery][playerx + 1] = 'N';
	map->n.xmap = playerx + 1;
	map->n.ymap = playery;
	if (map->n.xmap == map->p.xmap && map->n.ymap == map->p.ymap)
		return (ezzit(map));
	creatmap(map);
}

void	n_move_down(t_matrix *map, int playery, int playerx)
{
	map->map[playery][playerx] = '0';
	map->map[playery + 1][playerx] = 'N';
	map->n.xmap = playerx;
	map->n.ymap = playery + 1;
	if (map->n.xmap == map->p.xmap && map->n.ymap == map->p.ymap)
		return (ezzit(map));
	creatmap(map);
}

void	n_move_left(t_matrix *map, int playery, int playerx)
{
	map->map[playery][playerx] = '0';
	map->map[playery][playerx - 1] = 'N';
	map->n.xmap = playerx - 1;
	map->n.ymap = playery;
	if (map->n.xmap == map->p.xmap && map->n.ymap == map->p.ymap)
		return (ezzit(map));
	creatmap(map);
}
