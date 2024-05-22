/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:58:37 by tlukan            #+#    #+#             */
/*   Updated: 2024/01/26 16:04:36 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		pon;
	int		ris;

	ris = 0;
	pon = 1;
	i = 0;
	while (str[i] == 32 || ((str[i] > 8) && (str[i] < 14)))
		i ++;
	if (str[i] == 45)
		pon = -1;
	if (str[i] == 43)
		pon = 1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		ris = ris * 10 + str[i] - 48;
		i++;
	}
	return (ris * pon);
}
