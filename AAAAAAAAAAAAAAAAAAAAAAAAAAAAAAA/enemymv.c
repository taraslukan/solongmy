/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemymv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:23:32 by tlukan            #+#    #+#             */
/*   Updated: 2024/05/22 14:09:42 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	random2(t_matrix *map)
{
	int	enemyx;
	int	enemyy;

	enemyx = map->n.xmap;
	enemyy = map->n.ymap;
	if (map->map[enemyy][enemyx + 1] == '0'
	|| map->map[enemyy][enemyx + 1] == 'P')
		n_move_right(map, enemyy, enemyx);
	else if (map->map[enemyy + 1][enemyx] == '0'
	|| map->map[enemyy + 1][enemyx] == 'P')
		n_move_down(map, enemyy, enemyx);
	else if (map->map[enemyy][enemyx - 1] == '0'
	|| map->map[enemyy][enemyx - 1] == 'P')
		n_move_left(map, enemyy, enemyx);
	else if (map->map[enemyy - 1][enemyx] == '0'
	|| map->map[enemyy - 1][enemyx] == 'P')
		n_move_up(map, enemyy, enemyx);
}

void	random3(t_matrix *map)
{
	int	enemyx;
	int	enemyy;

	enemyx = map->n.xmap;
	enemyy = map->n.ymap;
	if (map->map[enemyy + 1][enemyx] != '1')
		n_move_down(map, enemyy, enemyx);
	else if (map->map[enemyy][enemyx - 1] != '1')
		n_move_left(map, enemyy, enemyx);
	else if (map->map[enemyy - 1][enemyx] != '1')
		n_move_up(map, enemyy, enemyx);
	else if (map->map[enemyy][enemyx + 1] != '1')
		n_move_right(map, enemyy, enemyx);
}

int	move_random(t_matrix *map, int numero, int enemyx, int enemyy)
{
	if (numero == 0)
	{
		if (map->map[enemyy - 1][enemyx] == '0'
		|| map->map[enemyy - 1][enemyx] == 'P')
			n_move_up(map, enemyy, enemyx);
	}
	else if (numero == 1)
	{
		if (map->map[enemyy][enemyx + 1] == '0'
		|| map->map[enemyy][enemyx + 1] == 'P')
			n_move_right(map, enemyy, enemyx);
	}
	else if (numero == 2)
		nunmericordo(map, enemyx, enemyy);
	else if (numero == 3)
	{
		if (map->map[enemyy][enemyx - 1] == '0'
		|| map->map[enemyy][enemyx - 1] == 'P')
			n_move_left(map, enemyy, enemyx);
	}
	return (1);
}
