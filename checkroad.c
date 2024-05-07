/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkroad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:15 by lukan             #+#    #+#             */
/*   Updated: 2024/05/03 21:13:59 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	clonemap(t_matrix *smap )
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
	
}

int	checkroad(t_matrix *checkmap)
{
	
}