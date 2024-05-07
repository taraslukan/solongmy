/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:53:41 by lukan             #+#    #+#             */
/*   Updated: 2024/05/03 15:38:33 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


static int	checkBer(char *location)
{
	size_t	len;
	
	len = ft_strlen(location);
	if ((location[len - 4] == '.') 
		&& (location[len - 3] == 'b') 
		&& (location[len - 2] == 'e') && (location[len - 1] == 'r'))
		return (1);
	else
		return (0);
}

static int	rect(t_matrix *checkmap)
{
	int y;
	
	y = 0;
	checkmap->maxX =(int) ft_strlen(checkmap->map[0]);
	while (checkmap->map[y])
	{
		if(checkmap->maxX == (int) ft_strlen(checkmap->map[y]))
			y++;
		else
			return (0);
	}
	if (y <= 2)
		return (0);
	else
		return (1);
}

static int	controlwall(t_matrix *checkmap)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while(checkmap->map[y])
	{
		if((checkmap->map[y][0] == '1')
			&& (checkmap->map[y][checkmap->maxX] == '1'))
			y++;
		else
			return (0);
	}	
	checkmap->maxY = y;
	while(checkmap->map[0][x])
	{
		if ((checkmap->map[0][x] == '1') 
			&& (checkmap->map[checkmap->maxY][x] == '1'))
			x++;
		else
			return (0);
	}
	return (1);
}

static int controlitems(t_matrix *checkmap)
{
	int	x;
	int	y;
	int	p;
	int	e;

	y = 0;
	while(checkmap->map[y])
	{
		x = 0;
		while (checkmap->map[y][x])
		{
			if(checkmap->map[y][x] == 'P')
				p++;
			if(checkmap->map[y][x] == 'E')
				e++;
			if(checkmap->map[y][x] == 'C')
				checkmap->c++;
			x++;
		}
		y++;
	}
	if((p == 1) && (e == 1) && (checkmap->c >= 1))
		return (1);
	else
		return (0);
}

int	checkmap(t_matrix *checkm, char *location)
{	
	
	if (checkBer(location) && rect(checkm) && controlwall(checkm) 
		&& controlitems(checkm) && checkroad(checkm))
			return (1);
		else 	
			return (0);
}