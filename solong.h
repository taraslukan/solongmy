#ifndef SOLONG_H
# define SOLONG_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_libft/libft.h"
#include "structsolong.h"
#include "liberror.h"

char    *strfromfile(int fd);
int		checkroad(t_matrix *checkmap);
int		checkmap(t_matrix *checkm, char *location);

#endif