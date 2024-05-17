/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkroad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:15 by lukan             #+#    #+#             */
/*   Updated: 2024/05/17 14:35:14 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	fld_fll_after(t_matrix *mappa, char **dublemap, int y, int x)
{
	if(dublemap[y][x] == '0' || dublemap[y][x] == 'C' 
	|| dublemap[y][x] == 'E' || dublemap[y][x] == 'P'
	|| dublemap[y][x] == 'N')
   {
		dublemap[y][x] = '1';
		if (y > 0 && dublemap[y - 1][x] != '1')
		fld_fll_after(mappa, dublemap, y - 1, x);
		if (x > 0 && dublemap[y][x - 1] != '1')
		fld_fll_after(mappa, dublemap, y, x - 1);
		if (y + 1 <mappa->maxy && dublemap[y + 1][x] != '1')
		fld_fll_after(mappa, dublemap, y + 1, x);
		if (x + 1 <mappa->maxx && dublemap[y][x + 1] != '1')
		fld_fll_after(mappa, dublemap, y, x + 1);
   }
}


static char	**flood_fill(t_matrix	*smap, char	**dublemap)
{
	fld_fll_after(smap, dublemap,smap->p.ymap ,smap->p.xmap);
	return(dublemap);
}

static int forfinish(char **dublemap)
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
	cloned = ft_calloc(sizeof(char**),smap->maxy + 1);
	while (i < smap->maxy)
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
	saveposition(checkmap);
	flood_fill(checkmap, dublemap);
	if(forfinish(dublemap))
   {
      del_clone(dublemap);
      return(1);
   }
   del_clone(dublemap);
   return(0);
}
