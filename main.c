/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:31 by lukan             #+#    #+#             */
/*   Updated: 2024/05/09 13:01:33 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc,char **argv)
{
	int			fd;
	char		*str;
	t_matrix	first;

	if (argc != 2)
		return (0);
	 fd = open(argv[1], O_RDONLY);
	 str = strfromfile(fd);
	 if (str == NULL)
	 	return (0);
	first.map = ft_split(str, '\n');
	free(str);
	if (checkmap(&first, argv[1]) == 0)
		del_clone(first.map);
	else
		exewindow();
	return (0);
}
