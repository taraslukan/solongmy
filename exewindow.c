/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exewindow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:15 by lukan             #+#    #+#             */
/*   Updated: 2024/05/21 16:18:17 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	imag_stamp(t_matrix *map , int y, int x)
{
	if (map->map[y][x] == '1')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
		map->img.wall, x * 100 , y * 100);
	else if (map->map[y][x] == 'C')
		coinmove(map, x, y);
	else if (map->map[y][x] == 'E')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
		map->img.exit, x * 100, y * 100 );
	else if (map->map[y][x] == 'P')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
		map->img.player, x * 100, y * 100 );
	else if (map->map[y][x] == 'N')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
		map->img.nemico, x * 100, y * 100 );
	else
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.wind,
		map->img.flor, x * 100, y * 100 );
}

void set_image(t_matrix	*map)
{    
    map->img.wall = mlx_xpm_file_to_image(map->mlx.mlx,
	 "xpm/wall.xpm", &(map->img.width), &(map->img.height));
    map->img.flor = mlx_xpm_file_to_image(map->mlx.mlx,
	 "xpm/path.xpm", &(map->img.width), &(map->img.height));
    map->img.coin1 = mlx_xpm_file_to_image(map->mlx.mlx,
	 "xpm/poke1.xpm", &(map->img.width), &(map->img.height));
	 map->img.coin2 = mlx_xpm_file_to_image(map->mlx.mlx,
	 "xpm/poke2.xpm", &(map->img.width), &(map->img.height));
	 map->img.coin3 = mlx_xpm_file_to_image(map->mlx.mlx,
	 "xpm/poke3.xpm", &(map->img.width), &(map->img.height));
	 map->img.coin4 = mlx_xpm_file_to_image(map->mlx.mlx,
	 "xpm/poke4.xpm", &(map->img.width), &(map->img.height));
	 map->img.coin5 = mlx_xpm_file_to_image(map->mlx.mlx,
	 "xpm/poke5.xpm", &(map->img.width), &(map->img.height));
    map->img.exit = mlx_xpm_file_to_image(map->mlx.mlx,
	 "xpm/E.xpm", &(map->img.width), &(map->img.height));
	map->img.player = mlx_xpm_file_to_image(map->mlx.mlx,
	 "xpm/plyr.xpm", &(map->img.width), &(map->img.height));
	map->img.nemico = mlx_xpm_file_to_image(map->mlx.mlx,
	 "xpm/enemy.xpm", &(map->img.width), &(map->img.height));
}

void creatmap(t_matrix *map)
{
	int		y;
	int		x;
	char	*ndoandamo;

	y = 0;
	x = 0;
	mlx_clear_window(map->mlx.mlx, map->mlx.wind);
	while (y < map->maxy)
	{ 
		while (x < map->maxx)
		{
			imag_stamp(map, y, x);
			x++;
		}
		y++;
		x = 0;
	}
	ndoandamo = ft_itoa(map->nm);
    mlx_string_put(map->mlx.mlx, map->mlx.wind, 100, 100, 0xFF00FF, "STEPS : ");
    mlx_string_put(map->mlx.mlx, map->mlx.wind, 150, 100, 0xFF00FF, ndoandamo);
	free(ndoandamo);
}

int k_hook(int k, t_matrix *map)
{
	
	if (k == KEY_ARROW_RIGHT || k == KEY_D)
		digitnm(map,'r');
    else if (k == KEY_ARROW_LEFT || k == KEY_A)
		digitnm(map,'l');
    else if (k == KEY_ARROW_UP || k == KEY_W)
		digitnm(map,'u');
    else if (k == KEY_ARROW_DOWN || k == KEY_S)
		digitnm(map,'d');
	else if (k == KEY_ESC)
		window_escape(map);
    return (0);
}

void	exewindow(t_matrix *map)
{
	int	x;
	int	y;
	
	x = map->maxx;
	y = map->maxy;
	map->img.ncoin = 0;
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
	mlx_loop_hook(map->mlx.mlx, randmv, map);
	mlx_loop(map->mlx.mlx);
} 
