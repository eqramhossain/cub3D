/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:49:50 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/24 21:17:38 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WALL_SIZE 64

# define MOVE_SPEED 0.10
# define ROT_SPEED 0.015

# define TRUE 1
# define FALSE 0

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_file
{
	char	*file_name;
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;
	char	*floor_color;
	char	*ceiling_color;
}			t_file;

typedef struct s_data
{
	t_file	*file;
}			t_data;

#endif
