/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemymv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:23:32 by tlukan            #+#    #+#             */
/*   Updated: 2024/05/15 15:17:09 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void random1(t_matrix *map)
{
	int	enemyx;
	int	enemyy;

	enemyx = map->n.xmap;
	enemyy = map->n.ymap;
	if (map->map[enemyy - 1][enemyx] != '1')
		n_move_up(map, enemyy, enemyx);
	else if (map->map[enemyy][enemyx + 1] != '1')
		n_move_right(map, enemyy, enemyx);
	else if (map->map[enemyy + 1][enemyx] != '1')
		n_move_down(map, enemyy, enemyx);
	else if (map->map[enemyy][enemyx - 1] != '1')
		n_move_left(map, enemyy, enemyx);
}

static void random2(t_matrix *map)
{
    int	enemyx;
	int	enemyy;

	enemyx = map->n.xmap;
	enemyy = map->n.ymap;
    if (map->map[enemyy][enemyx + 1] != '1')
        n_move_right(map, enemyy, enemyx);
    else if (map->map[enemyy + 1][enemyx] != '1')
        n_move_down(map, enemyy, enemyx);
    else if (map->map[enemyy][enemyx - 1] != '1')
        n_move_left(map, enemyy, enemyx);
    else if (map->map[enemyy - 1][enemyx] != '1')
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

static void random4(t_matrix *map)
{
    int	enemyx;
	int	enemyy;

	enemyx = map->n.xmap;
	enemyy = map->n.ymap;

    if (map->map[enemyy][enemyx - 1] != '1')
        n_move_left(map, enemyy, enemyx);
    else if (map->map[enemyy - 1][enemyx] != '1')
        n_move_up(map, enemyy, enemyx);
    else if (map->map[enemyy][enemyx + 1] != '1')
        n_move_right(map, enemyy, enemyx);
    else if (map->map[enemyy + 1][enemyx] != '1')
        n_move_down(map, enemyy, enemyx);
}

int move_random(t_matrix *map, int numero, int enemyx, int enemyy)
{
    if (numero == 0)
	{
    	if (map->map[enemyy - 1][enemyx] != '1')
			n_move_up(map, enemyy, enemyx);
    	else
			random1(map);
	}
	else if (numero == 1)
	{
		if (map->map[enemyy][enemyx + 1] != '1')
			n_move_right(map, enemyy, enemyx);
		else
            random2(map);
    }
	else if (numero == 2)
		nunmericordo(map,enemyx, enemyx);
	else if (numero == 3)
	{
		if (map->map[enemyy][enemyx - 1] != '1')
            n_move_left(map, enemyy, enemyx);
		else
			random4(map);
    }
    return 1;
}
