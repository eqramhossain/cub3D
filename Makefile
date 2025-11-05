# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egerin <egerin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 13:37:08 by egerin            #+#    #+#              #
#    Updated: 2025/11/05 15:16:26 by egerin           ###   ########.fr        #
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

NAME = cub3d
LIBFT = libft.a
MLX = minilibx-linux/libmlx.a
MLX_DIR = minilibx-linux/
LIBFT_DIR = libft/

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I${LIBFT} -Iincludes -I${MLX_DIR}
MLX_FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm
LDFLAGS = -L${LIBFT_DIR} -lft

SRC_FILES = src/main.c src/parsing.c
SRC = $(SRC_FILES)
OBJ = $(SRC:.c=.o)

%.o:%.c
	@$(CC) $(CFLAGS) -c -g3 $< -o $@

$(NAME): $(OBJ) $(LIBFT) ${MLX}
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) ${MLX_FLAGS} -o $(NAME)
	@echo "✅ $(_GREEN)Compiled succesfully ! ✅"


all: $(NAME)

$(LIBFT): ${LIBFT_DIR}
	@make --no-print-directory -C $(LIBFT_DIR)

${MLX}:
	@make --no-print-directory -C ${MLX_DIR}

clean:
	@make --no-print-directory clean -C ${LIBFT_DIR}
	@make --no-print-directory clean -C ${MLX_DIR}
	@rm -f $(OBJ)
	@echo "🚮 $(_RED)Deleted succesfully ! 🚮"

fclean: clean
	@make --no-print-directory fclean -C ${LIBFT_DIR}
	@rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
