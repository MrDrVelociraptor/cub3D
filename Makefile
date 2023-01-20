# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 16:11:55 by nspeedy           #+#    #+#              #
#    Updated: 2023/01/16 13:18:48 by nspeedy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
 
SRCS = src/*.c

MLX = mlx
LIBFT = libft
INC = inc

LIBS = -L$(MLX) -lmlx -L$(LIBFT) -lft
HEADERS = -I$(INC) -I$(MLX) -I$(LIBFT)
FLAGS = $(LIBS) $(HEADERS) -framework OpenGL -framework AppKit

all:
	clear
	@make -s -C $(MLX)
	@make -s -C $(LIBFT)
	@gcc $(SRCS) $(FLAGS) -o $(NAME)
	@echo Compiling libraries

clean:
	clear
	@make clean -s -C $(MLX)
	@make fclean -s -C $(LIBFT)
	@rm -f $(NAME)
	@echo Cleaning up
	@echo Wax on, wax off
	
fclean: clean

re: clean all
