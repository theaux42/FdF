# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 16:03:21 by tbabou            #+#    #+#              #
#    Updated: 2024/08/16 15:53:39 by tbabou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  fdf.c srcs/parser.c srcs/coords.c srcs/drawing.c srcs/movement.c \
		srcs/utils.c srcs/line.c srcs/init.c

OBJ = $(SRC:.c=.o)

BINARY_NAME = fdf

COMPILER = cc

MANDATORY_FLAGS = -Wall -Wextra -Werror -g3
MINILIBX_FLAGS = -L./minilibx/ -lmlx -lXext -lX11 -lm -lbsd
LIBFT_FLAGS = -L./libft/ -lft

all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJ)
	make -C libft
	make -C minilibx
	$(COMPILER) $(MANDATORY_FLAGS) $(OBJ) $(MINILIBX_FLAGS) $(LIBFT_FLAGS) -o $(BINARY_NAME)

%.o: %.c
	$(COMPILER) $(MANDATORY_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BINARY_NAME)

ffclean: fclean
	make -C libft fclean
	make -C minilibx clean
	
re: fclean all
	@echo "🚀 done"

fre: ffclean all
	@echo "🚀 done"

.PHONY: all clean fclean ffclean re fre