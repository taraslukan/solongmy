/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exewindow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:15 by lukan             #+#    #+#             */
/*   Updated: 2024/05/13 14:46:12 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	imag_stamp(t_matrix *map , int y, int x)
{
	if (map->matrix[y][x] == '1')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
		 map->img.wall, x * 100 , y * 100);
	else if (map->matrix[y][x] == 'C')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
		 map->img.coin, x * 100 , y * 100);
	else if (map->matrix[y][x] == 'E')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
		 map->img.exit, x * 100, y * 100 );
	else if (map->matrix[y][x] == 'P')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
		 map->img.player, x * 100, y * 100 );
	else if (map->matrix[y][x] == 'A')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
		 map->img.nemico, x * 100, y * 100 );
	else
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
		 map->img.flor, x * 100, y * 100 );
}

void set_image(t_matrix	*map)
{    
    map->img.wall = mlx_xpm_file_to_image(map->mlx.mlx,
	 "img/WALL_1.xpm", &(map->img.width), &(map->img.height));
    map->img.flor = mlx_xpm_file_to_image(map->mlx.mlx,
	 "img/new/pavimento(sci-fi).xpm", &(map->img.width), &(map->img.height));
    map->img.coin = mlx_xpm_file_to_image(map->mlx.mlx,
	 "img/coin.xpm", &(map->img.width), &(map->img.height));
    map->img.exit = mlx_xpm_file_to_image(map->mlx.mlx,
	 "img/OPENTRS.xpm", &(map->img.width), &(map->img.height));
	map->img.player = mlx_xpm_file_to_image(map->mlx.mlx,
	 "img/pirat.xpm", &(map->img.width), &(map->img.height));
	map->img.nemico = mlx_xpm_file_to_image(map->mlx.mlx,
	 "img/new/nemico.xpm", &(map->img.width), &(map->img.height));
}

void creatmap(t_matrix *map)
{
	mlx_clear_window(map->mlx.mlx, map->mlx.wind);
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < map->maxY)
	{ 
		while (x < map->maxX)
		{
			imag_stamp(map, y, x);
			x++;
		}
		y++;
		x = 0;
	}
}

int k_hook(int k, t_matrix *map)
{
	if (k == KEY_ARROW_RIGHT || k == KEY_D)
		move_right(map);
    else if (k == KEY_ARROW_LEFT || k == KEY_A)
		move_left(map);
    else if (k == KEY_ARROW_UP || k == KEY_W)
		move_up(map);
    else if (k == KEY_ARROW_DOWN || k == KEY_S)
		move_down(map);
	else if (k == KEY_ESC)
		window_escape(map);
    return (0);
}

void	exewindow(t_matrix *map)
{
	int	x;
	int	y;
	
	x = map->maxX;
	y = map->maxY;
	map->mlx.wind = NULL;
	map->mlx.mlx = NULL;
	map->mlx.mlx = mlx_init();
	map->mlx.wind = mlx_new_window(map->mlx.mlx, x * 100, y * 100, "test");
	map->img.height = 100;
	map->img.width = 100;
	set_image(map);
	creatmap(map);
	mlx_key_hook(map->mlx.wind, k_hook, map);
	mlx_hook(map->mlx.wind, 17, 0, window_escape, map);
	mlx_loop_hook(map->mlx.mlx, randomeMoveInit, map);
	mlx_loop(map->mlx.mlx);
}