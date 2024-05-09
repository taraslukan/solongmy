#include "solong.h"

int	error(int error)
{	
	
	if(error == 1)
		ft_putstr_fd(ERROR_1, 1);
	else if (error == 2)
		ft_putstr_fd(ERROR_2, 1);
	else if (error == 3)
		ft_putstr_fd(ERROR_3, 1);
	else if (error == 4)
		ft_putstr_fd(ERROR_4, 1);
	else if (error == 5)
		ft_putstr_fd(ERROR_5, 1);
	else if (error == 6)
		ft_putstr_fd(ERROR_6, 1);
	return (0);
}

int	close_matrix(char **matrix)
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