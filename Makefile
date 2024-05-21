# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lXext -lX11 -lm -lbsd

# Directories

LIBFTDIR = ./ft_libft
MLXDIR = ./minilibx-linux

# Source files
SRCS = strfromfile.c saveitems.c main.c error.c movepl.c exewindow.c enemymv.c checkroad.c checkmap.c randmv.c nmove.c
OBJS = $(SRCS:%.c=%.o)

# Executable name
NAME = so_long

all: $(NAME)

%.o: %.c | $(OBJS)
	${CC} ${CFLAGS} -I$(MLXDIR) -g -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C $(MLXDIR)
	make -C $(LIBFTDIR)
	$(CC) $(OBJS) -L$(MLXDIR) -lmlx_Linux -L$(LIBFTDIR) -lft $(MFLAGS) -o $(NAME)



clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# #*
# SRC = checkPath.c fdToStr.c main.c error.c mapControl.c saveObjPosition.c stampMatrix.c libft/libft.a
# SRCB = checkPath.c fdToStr.c main.c error.c mapControl.c saveObjPosition.c stampMatrix.c
# OBJ = $(SRCB:%.c=%.o)

# MLXDIR = minilibx-linux/mlx


# CFLAGS = -Wall -Wextra -Werror 
# LIBSFLAG = -L$(LIBFTDIR) -lft -L$(FT_PRINTFDIR) -lftprintf -L$(MLXDIR) -lmlx_Linux
# cc = gcc

# OUTPUTNAME = so_long
# RM = rm -r


# all: $(OBJ)
# 	@$(CC) $(CFLAGS) $(OBJ) -o $(OUTPUTNAME)

# fclean: clean
# 	$(RM) $(OBJ)

# re: 
# 	@$(MAKE) all
# 	@rm *.o 
# 	@echo "Ho eseguito e cancellato tutto"

# .PHONY: all clean fclean re
