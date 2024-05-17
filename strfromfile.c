/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strfromfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:33:45 by tlukan            #+#    #+#             */
/*   Updated: 2024/05/15 16:14:27 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*strfromfile(int fd)
{
	ssize_t	countread;
	char    buffer[10];
	char	*ret;
	char	*totfree;

	ret = ft_strdup("");
	countread = 1;
	while (countread > 0)
	{
		countread = read(fd, buffer, 9);
		if (countread > 0)
		{
			buffer[countread] = 0;
            totfree = ret;
            ret = ft_strjoin(totfree, buffer);
            free(totfree);
		}
	}
	if (ft_strlen(ret) == 0 || fd < 0)
    {
        ft_putstr_fd("Error 104 by tarallo, file not found ", 1);
        return (NULL);
    }
    return ret;
}
