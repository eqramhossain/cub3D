# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 10:51:38 by ehossain          #+#    #+#              #
#    Updated: 2026/01/24 13:02:21 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
LIB_MLX = ./minilibx-linux/libmlx.a
DIR_MLX = ./minilibx-linux

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
INCLUDE_FLAGS = -I${LIBFT_DIR} -Iincludes -I${DIR_MLX}
MLX_FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm -g3
LDFLAGS = -L${LIBFT_DIR} -lft
MAKE = make --no-print-directory

SRC_PARSING = ./src/main.c
OBJ_PARSING = $(SRC_PARSING:.c=.o)

SRC_RAYCAST = 
OBJ_RAYCAST = $(SRC_RAYCAST:.c=.o)

all = $(NAME)

$(NAME): $(OBJ) $(LIBFT) ${LIB_MLX}
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_PARSING) $(OBJ_RAYCAST) $(LIB_MLX) $(LIBFT) ${MLX_FLAGS} $(LDFLAGS)
	@echo "$(GREEN)cub3D compiled$(END)"

%.o:%.c
	@$(CC) $(CFLAGS) -c -g3 $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

${LIB_MLX}:
	@$(MAKE) -C ${DIR_MLX} > /dev/null 2>&1

clean :
	rm -f $(OBJ_PARSING) $(OBJ_RAYCAST)

fclean :
	rm -f $(OBJ_PARSING) $(OBJ_RAYCAST)
	rm -f $(NAME)

re : fclean all

norm: norminette ./src

.PHONY : clean fclean re all

RED    = \033[0;31m
GREEN  = \033[0;32m
END     = \033[0m
