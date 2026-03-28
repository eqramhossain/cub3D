# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 10:51:38 by ehossain          #+#    #+#              #
#    Updated: 2026/03/25 07:35:16 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
LIB_MLX = ./minilibx-linux/libmlx.a
DIR_MLX = ./minilibx-linux

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I${LIBFT_DIR} -Iinclude -I${DIR_MLX}
MLX_FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm -g3
LDFLAGS = -L${LIBFT_DIR} -lft
MAKE = make --no-print-directory

SRC_PARSING = ./src/main.c \
			  ./src/parsing/ft_error.c \
			  ./src/parsing/ft_check_file_extention.c \
			  ./src/parsing/ft_read.c \
			  ./src/parsing/ft_free_t_data.c \
			  ./src/parsing/ft_parsing.c \
			  ./src/parsing/ft_check_texture_flag.c \
			  ./src/parsing/ft_check_texture_file.c \
			  ./src/parsing/ft_store_texture_file.c \
			  ./src/parsing/ft_check_fc_flag.c \
			  ./src/parsing/ft_store_fc_color.c \
			  ./src/parsing/ft_is_rgb_valid.c \
			  ./src/parsing/ft_check_map.c \
			  ./src/parsing/ft_check_map2.c \
			  ./src/parsing/ft_is_map_valid.c \
			  ./src/parsing/ft_extract_player_info.c \


SRC_RAYCAST = ./src/raycast/ft_init_mlx.c \
			  ./src/raycast/ft_is_a_valid_move.c \
			  ./src/raycast/ft_move_player_pos.c \
			  ./src/raycast/ft_raycaster_engine.c \
			  ./src/raycast/ft_raycasting.c \
			  ./src/raycast/ft_rotate_player.c \

SRC_ALL = $(SRC_PARSING) $(SRC_RAYCAST)

OBJ = $(SRC_ALL:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) $(LIBFT) ${LIB_MLX}
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_MLX) $(LIBFT) ${MLX_FLAGS} $(LDFLAGS)
	@echo "$(GREEN)cub3D compiled$(END)"

%.o: %.c
	@$(CC) $(CFLAGS) -c -g3 $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

${LIB_MLX}:
	@$(MAKE) -C ${DIR_MLX} > /dev/null 2>&1

clean :
	@$(MAKE) clean -C ${LIBFT_DIR}
	@$(MAKE) clean -C ${DIR_MLX} > /dev/null 2>&1
	@rm -f $(OBJ)
	@echo "$(RED)cub3D object files removed$(END)"

fclean :
	@$(MAKE) fclean -C ${LIBFT_DIR}
	@$(MAKE) clean -C ${DIR_MLX} > /dev/null 2>&1
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "$(RED)cub3D object files removed$(END)"
	@echo "$(RED)cub3D removed$(END)"

re : fclean all

norm:
	norminette include libft src

.PHONY : clean fclean re all norm

RED    = \033[0;31m
GREEN  = \033[0;32m
END     = \033[0m
