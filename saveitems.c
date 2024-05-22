/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveitems.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:47:23 by tlukan            #+#    #+#             */
/*   Updated: 2024/05/22 12:49:24 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	save_position_struct(t_matrix	*mappa, int y, int x, char type)
{
	if (type == 'P')
	{
		mappa->p.nitems = 'P';
		mappa->p.xmap = x;
		mappa->p.ymap = y;
	}
	else if (type == 'E')
	{
		mappa->e.nitems = 'E';
		mappa->e.xmap = x;
		mappa->e.ymap = y;
	}
	else if (type == 'N')
	{
		mappa->n.nitems = 'N';
		mappa->n.xmap = x;
		mappa->n.ymap = y;
	}
}

void	saveposition(t_matrix *mappa)
{
	int	y;
	int	x;

	y = 0;
	while (y < mappa->maxy)
	{
		x = 0;
		while (x < mappa->maxx)
		{
			if (mappa->map[y][x] == 'P')
				save_position_struct(mappa, y, x, 'P');
			if (mappa->map[y][x] == 'N')
				save_position_struct(mappa, y, x, 'N');
			if (mappa->map[y][x] == 'C' )
				save_position_struct(mappa, y, x, 'C');
			if (mappa->map[y][x] == 'E')
				save_position_struct(mappa, y, x, 'E');
			x++;
		}
		y++;
	}
}
