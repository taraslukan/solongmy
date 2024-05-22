/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structsolong.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:55:45 by tlukan            #+#    #+#             */
/*   Updated: 2024/05/22 12:57:53 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTSOLONG_H
# define STRUCTSOLONG_H

# define NUM_COLLECTABLE 5
# define MAX_XPM 5

typedef struct s_items
{
	void	*img;
	char	nitems;
	int		xmap;
	int		ymap;
}	t_items;

typedef struct s_img
{
	void	*wall;
	void	*flor;
	int		ncoin;	
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*exit;
	void	*nemico;
	void	*player;
	int		width;
	int		height;
}	t_img;

typedef struct s_wmlx
{
	void	*wind;
	void	*mlx;
}	t_wmlx;

typedef struct s_matrix
{
	int		maxx;
	int		entrue;
	int		maxy;
	char	**map;
	int		c;
	t_items	p;
	t_items	e;
	t_items	f;
	t_items	n;
	t_wmlx	mlx;
	t_img	img;
	int		nm;
}	t_matrix;

#endif