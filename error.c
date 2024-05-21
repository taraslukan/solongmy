#include "solong.h"

int	error(int error)
{	
	
	if(error == 1)
		ft_putstr(ERROR_1);
	else if (error == 2)
		ft_putstr(ERROR_2);
	else if (error == 3)
		ft_putstr(ERROR_3);
	else if (error == 4)
		ft_putstr(ERROR_4);
	else if (error == 5)
		ft_putstr(ERROR_5);
	else if (error == 6)
		ft_putstr(ERROR_6);
	else if (error == 7)
		ft_putstr(ERROR_7);
	return (0);
}

int	del_clone(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y] != NULL)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
	return (1);
}

int	test(t_matrix *checkm, int x, int y)
{
	
	while(checkm->map[++y])
	{
		x = -1;
		while (checkm->map[y][++x])
		{
			if(checkm->map[y][x] != 'P' && checkm->map[y][x] != 'E'
			&& checkm->map[y][x] != 'N' && checkm->map[y][x] != 'C'
			&& checkm->map[y][x] != '1' && checkm->map[y][x] != '0')
			{
				error(7);
				return (0);
			}
		}
	}
	return(1);
}