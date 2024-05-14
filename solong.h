#ifndef SOLONG_H
# define SOLONG_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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




char    *strfromfile(int fd);
int		checkroad(t_matrix *checkmap);
int		checkmap(t_matrix *checkm, char *location);

#endif