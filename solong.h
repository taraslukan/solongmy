#ifndef SOLONG_H
# define SOLONG_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mlxlin/mlx.h"
#include <fcntl.h>
#include "ft_libft/libft.h"
#include "structsolong.h"
#include "liberror.h"

#define KEY_ARROW_RIGHT 65363
#define KEY_ARROW_LEFT 65361
#define KEY_ARROW_UP 65362
#define KEY_ARROW_DOWN 65364

#define KEY_D 100
#define KEY_A 97
#define KEY_W 119
#define KEY_S 115

#define KEY_ESC 65307
void	random3(t_matrix *map);
void    n_move_right(t_matrix *map, int playery,int playerx);
void    n_move_up(t_matrix *map, int playery,int playerx);;
void    n_move_down(t_matrix *map, int playery,int playerx);
void    n_move_left(t_matrix *map, int playery,int playerx);
void    nunmericordo(t_matrix *map, int enemyx, int enemyy);
char	*strfromfile(int fd);
int		checkroad(t_matrix *checkmap);
int		checkmap(t_matrix *checkm, char *location);
void	saveposition(t_matrix *mappa);
int		del_clone(char **matrix);
void	set_image(t_matrix *map);
void	creatmap(t_matrix *map);
int		k_hook(int k, t_matrix *map);
void	exewindow(t_matrix *map);
int		window_escape(t_matrix *map);
void	m_down(t_matrix *map);
void	m_up(t_matrix *map);
void	m_left(t_matrix *map);
void	m_right(t_matrix *map);
void	m_down(t_matrix *map);
int		move_random(t_matrix *map, int numero, int enemyx, int enemyy);
int		error(int error);
int		randmv(t_matrix *map);

#endif