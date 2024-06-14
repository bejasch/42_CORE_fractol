# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 09:10:01 by bschneid          #+#    #+#              #
#    Updated: 2024/06/13 10:30:28 by bschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_DIR = src
OBJ_DIR = obj
SOURCES = main.c color.c mouse.c keys.c grafic.c mandelbrot.c julia.c\
	burning.c jurning.c menger.c calculate.c moving.c utils.c
OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))
FLAGS = -Wall -Werror -Wextra -g

all:	$(NAME)

$(NAME): $(OBJECTS)
	cc $(FLAGS) $(OBJECTS) -o $@ -L. -lmlx -lX11 -lXext -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
