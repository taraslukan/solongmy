/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randmv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:04:45 by tlukan            #+#    #+#             */
/*   Updated: 2024/05/15 15:02:45 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int randmv(t_matrix *map)
{
    
    int	numero;
    int	enemyx;
    int	enemyy;
    
    usleep(200000);
    numero = rand() % 4;
    srand(time(NULL));
    enemyx = map->n.ymap;
    enemyy = map->n.xmap;
    move_random(map,  numero, enemyx, enemyy);
    return(1);   
}

void	nunmericordo(t_matrix *map, int enemyx, int enemyy)
{
		if (map->map[enemyy + 1][enemyx] != '1')
			n_move_down(map, enemyy, enemyx);
		else
			random3(map);
}
