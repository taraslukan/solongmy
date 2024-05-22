/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randmv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:04:45 by tlukan            #+#    #+#             */
/*   Updated: 2024/05/22 12:46:59 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	randmv(t_matrix *map)
{
	int	numero;
	int	enemyx;
	int	enemyy;

	usleep(200000 / 2);
	numero = rand() % 4;
	srand(time(NULL));
	if (map->img.ncoin >= 5)
		map->img.ncoin = 1;
	else
		map->img.ncoin++;
	if (map->entrue)
	{
		enemyy = map->n.ymap;
		enemyx = map->n.xmap;
		move_random(map, numero, enemyx, enemyy);
	}
	creatmap(map);
	return (1);
}

void	nunmericordo(t_matrix *map, int enemyx, int enemyy)
{
	if (map->map[enemyy + 1][enemyx] == '0'
		|| map->map[enemyy + 1][enemyx] == 'P')
		n_move_down(map, enemyy, enemyx);
}

void	ezzit(t_matrix *map)
{
	ft_putstr("La partita é finita.\n");
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
	free(map->mlx.mlx);
	free(map->mlx.wind);
	exit(1);
}

void	coinmove(t_matrix *map, int x, int y)
{
	if (map->img.ncoin == 1)
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
			map->img.coin1, x * 100, y * 100);
	if (map->img.ncoin == 2)
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
			map->img.coin2, x * 100, y * 100);
	if (map->img.ncoin == 3)
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
			map->img.coin3, x * 100, y * 100);
	if (map->img.ncoin == 4)
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
			map->img.coin4, x * 100, y * 100);
	if (map->img.ncoin == 5)
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
			map->img.coin5, x * 100, y * 100);
}

int	escapeex(t_matrix *map)
{
	if (map->c == 0)
		return (1);
	else
		return (0);
}
