/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:43:44 by tlukan            #+#    #+#             */
/*   Updated: 2024/01/31 17:46:09 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*c_b;

	i = 0;
	c_b = (char *)b;
	while (i < len)
	{
		c_b[i] = c;
		i++;
	}
	return (b);
}
