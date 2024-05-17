/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:31 by lukan             #+#    #+#             */
/*   Updated: 2024/05/17 15:14:26 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void map(t_matrix *map)
{
	int		y;
	int		x;

	y = 0;
	printf(" map->maxy%d\n", map->maxx);

	while (y < map->maxy)
	{ 
		x = 0;
		printf("map->map%s",map->map[y]);
		while (x < map->maxx)
		{
			x++;
		}
		y++;
	}
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
	printf("\nmachecazzosucced\n");
	if (checkmap(&first, argv[1]) == 0)
	{
		printf("diodelclone\n");
		del_clone(first.map);
	}
	else
	{
	printf("checkmap ==%i\n", checkmap(&first, argv[1]));
	map(&first);
		exewindow(&first);
		printf("dajje \n");	
	}
	return (0);
}
