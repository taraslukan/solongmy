/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkroad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:15 by lukan             #+#    #+#             */
/*   Updated: 2024/05/08 17:14:31 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	fld_fll_after(t_matrix *mappa, char **dublemap, int y, int x)
{
	if(dublemap[y][x] == '0' || dublemap[y][x] == 'C' 
	|| dublemap[y][x] == 'E' || dublemap[y][x] == 'P')
   {
		dublemap[y][x] = '3';
		if (y > 0 && dublemap[y - 1][x] != '1')
		fld_fll_after(mappa, dublemap, y - 1, x);
		if (x > 0 && dublemap[y][x - 1] != '1')
		fld_fll_after(mappa, dublemap, y, x - 1);
		if (y + 1 <mappa->maxY && dublemap[y + 1][x] != '1')
		fld_fll_after(mappa, dublemap, y + 1, x);
		if (x + 1 <mappa->maxX && dublemap[y][x + 1] != '1')
		fld_fll_after(mappa, dublemap, y, x + 1);
   }
}

static char	**flood_fill(t_matrix	*smap, char	**dublemap)
{
	int	x;
	int	y;
	
	y = smap->p.ymap;
	x = smap->p.xmap;
	fld_fll_after(smap, dublemap,x ,y);
	return(dublemap);
}

static int getConclusions(char **dublemap)
{
   int y;
   int x;

   y = 0;
   while (dublemap[y])
	{
		x = 0;
		while (dublemap[y][x])
		{
			if (dublemap[y][x] == 'P' 
			|| dublemap[y][x] == 'C' || dublemap[y][x] == 'E')
           return(error(6));
			x++;
		}
		y++;
	}
   return (1);
}

static char	**clonemap(t_matrix *smap )
{
	char	**cloned;
	int		i;
	
	i = 0;
	cloned = ft_calloc(sizeof(char**),smap->maxY + 1);
	while (i < smap->maxY)
	{
		cloned[i] = ft_strdup(smap->map[i]);
		i++;
	}
	return (cloned);
	
}

int	checkroad(t_matrix *checkmap)
{
	char	**dublemap;
	
	dublemap = clonemap(checkmap);
	positionsave(checkmap,0);
	flood_fill(checkmap, dublemap);
	if(getConclusions(dublemap))
   {
      close_matrix(dublemap);
      return(1);
   }
   close_matrix(dublemap);
   return(0);
}
