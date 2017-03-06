# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 11:37:19 by abourgeu          #+#    #+#              #
#    Updated: 2017/03/01 11:24:59 by abourgeu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror

SRC = 	srcs/main.c srcs/key_code.c srcs/algo_draw.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C ./libft
	@gcc $(CFLAGS) -o $(NAME) -framework OpenGL -framework AppKit \
	minilibx/libmlx.a -lft -L./libft -I./libft $(OBJ)
	@echo "FDF compiled."

all: $(NAME)

clean:
	make -C ./libft clean
	rm -rf $(OBJ)

fclean : clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean make fclean re
