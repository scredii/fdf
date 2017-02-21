# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 11:37:19 by abourgeu          #+#    #+#              #
#    Updated: 2017/02/07 15:57:40 by abourgeu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror

SRC = 	src/main.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	make --no-print-directory -C ./libft
	@gcc $(CFLAGS) -o $(NAME) -framework OpenGL -framework AppKit \
	minilibx/libmlx.a -lft -L./libft -I./libft $(OBJ)
	@echo "Libft compiled."

all: $(NAME)

clean:
	make -C ./libft clean
	rm -rf $(OBJ)

fclean : clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean all
