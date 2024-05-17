/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:53:41 by lukan             #+#    #+#             */
/*   Updated: 2024/05/17 14:59:46 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


static int	checkber(char *location)
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
	checkmap->maxx =(int) ft_strlen(checkmap->map[0]);
	while (checkmap->map[y])
	{
		if(checkmap->maxx == (int) ft_strlen(checkmap->map[y]))
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
		if(!(checkmap->map[y][0] == '1')
			&& (checkmap->map[y][checkmap->maxx] == '1'))
			return (0);
		y++;
	}	
	checkmap->maxy = y;
	while(checkmap->map[0][x])
	{
		if (!(checkmap->map[0][x] == '1') 
			&& (checkmap->map[checkmap->maxy - 1][x] == '1'))
			return (0);
		x++;
	}
	return (1);
}

static int controlitems(t_matrix *checkmap)
{
	int	x;
	int	y;
	int	p;
	int	e;

	y = -1;
	p = 0;
	e = 0;	
	while(checkmap->map[++y])
	{
		x = -1;
		while (checkmap->map[y][++x])
		{
			if(checkmap->map[y][x] == 'P')
				p++;
			if(checkmap->map[y][x] == 'E')
				e++;
			if(checkmap->map[y][x] == 'C')
				checkmap->c++;
		}
	}
	if((p == 1) && (e == 1) && (checkmap->c >= 1))
		return (1);
	else
		return (0);
}

int	checkmap(t_matrix *checkm, char *location)
{	
	//printf("%i , %i , %i , %i , %i \n",checkber(location), rect(checkm), controlwall(checkm), controlitems(checkm), checkroad(checkm));
	if (checkber(location) && rect(checkm) && controlwall(checkm) 
		&& controlitems(checkm) && checkroad(checkm))
		
			return (1);
		else 	
	{
			return (0);
	}
}