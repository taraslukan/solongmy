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