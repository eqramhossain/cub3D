# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egerin <egerin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 13:37:08 by egerin            #+#    #+#              #
#    Updated: 2025/11/18 18:13:21 by egerin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_GREY=$'\x1b[30m'
_RED=\e[1;31m
_GREEN=\e[1;32m
_YELLOW=$'\x1b[33m'
_BLUE=$'\x1b[34m'
_PURPLE=$'\x1b[35m'
_CYAN=$'\x1b[36m'
_WHITE=$'\x1b[37m'

NAME = cub3D
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
LIB_MLX = ./minilibx-linux/libmlx.a
DIR_MLX = ./minilibx-linux

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I${LIBFT_DIR} -Iincludes -I${DIR_MLX}
MLX_FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm
LDFLAGS = -L${LIBFT_DIR} -lft
MAKE = make --no-print-directory

SRC = ./src/parsing/main.c\
	  ./src/parsing/parsing.c\
	  ./src/parsing/parsing2.c\
	  ./src/parsing/utils.c\
	  ./src/parsing/sprites.c\
	  ./src/parsing/position.c \
	  ./src/parsing/utils2.c \
	  ./src/parsing/utils3.c \
	  ./src/parsing/parsing3.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) ${LIB_MLX}
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_MLX) $(LIBFT) ${MLX_FLAGS} $(LDFLAGS)
	@echo "$(_GREEN)cub3D compiled"

%.o:%.c
	@$(CC) $(CFLAGS) -c -g3 $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

${LIB_MLX}:
	@$(MAKE) -C ${DIR_MLX} > /dev/null 2>&1

clean:
	@$(MAKE) clean -C ${LIBFT_DIR}
	@$(MAKE) clean -C ${DIR_MLX} > /dev/null 2>&1
	@rm -f $(OBJ)
	@echo "$(_RED)cub3D object files removed"

fclean:
	@$(MAKE) fclean -C ${LIBFT_DIR}
	@$(MAKE) clean -C ${DIR_MLX} > /dev/null 2>&1
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "$(_RED)cub3D object files removed"
	@echo "$(_RED)cub3D removed"

re: fclean all

.PHONY: all clean fclean re
