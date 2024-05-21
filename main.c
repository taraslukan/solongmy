/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:31 by lukan             #+#    #+#             */
/*   Updated: 2024/05/21 17:25:52 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
void	digitnm(t_matrix *map, char a)
{
	map->nm++;
	 if(a == 'r')
	 	m_right(map);
	if(a == 'l')
		m_left(map);
	if(a == 'u')
		m_up(map);
	if(a == 'd')
		m_down(map);
}

int	main(int argc,char **argv)
{
	int			fd;
	char		*str;
	t_matrix	first;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	str = strfromfile(fd);
	close(fd);
	 if (str == NULL)
	 	return (0);
	first.map = ft_split(str, '\n');
	free(str);
	first.nm = 0;
	if (checkmap(&first, argv[1]) == 0)
		del_clone(first.map);
	else
		exewindow(&first);
	return (0);
}
