/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:49:50 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/29 14:22:43 by ehossain         ###   ########.fr       */
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

# define SUCCESS 0
# define ERROR 1

# define TRUE 1
# define FALSE 0

# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ray
{
}					t_ray;

typedef struct s_player
{
	char			dir;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				has_moved;
	int				move_x;
	int				move_y;
	int				rotate;
}					t_player;

typedef struct s_tex_helper
{
	void			*no_wall;
	void			*so_wall;
	void			*we_wall;
	void			*ea_wall;
	char			*no_addr;
	char			*so_addr;
	char			*we_addr;
	char			*ea_addr;
	int				no_bpp;
	int				so_bpp;
	int				we_bpp;
	int				ea_bpp;
	int				no_line_len;
	int				so_line_len;
	int				we_line_len;
	int				ea_line_len;
	int				no_end;
	int				so_end;
	int				we_end;
	int				ea_end;
}					t_tex_helper;

typedef struct s_texture
{
	char			*no_texture;
	char			*so_texture;
	char			*ea_texture;
	char			*we_texture;
	int				floor;
	int				ceiling;
	int				floor_tab[3];
	int				ceiling_tab[3];
	t_tex_helper	tex_helper;
}					t_texture;

typedef struct s_img
{
	void			*img_ptr;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_data
{
	char			**file_content;
	char			*file_name;
	void			*mlx_ptr;
	void			*win_ptr;
	t_texture		*texture;
	t_player		*player;
	t_img			*img;
	t_ray			*ray;
}					t_data;

void				ft_error(char *str);
int					ft_check_file_extention(char *file_name);
char				*ft_read(t_data *data);
void				ft_free_t_data(t_data *data);
int					ft_parsing(t_data *data);
int					ft_check_file(t_data *data);

int					ft_check_all_texture_flag(t_data *data);
int					ft_check_all_texture_file(t_data *data);
char				*ft_find_texture_line(char **file_content,
						char *identifier);

char				*ft_extract_texture_path(char *line, char *identifier);
int					ft_store_all_texture_file(t_data *data);

int					ft_check_floor_ceiling_flag(t_data *data);
int					ft_store_floor_ceiling_color(t_data *data);
int					ft_is_rgb_valid(t_texture *texture);

/* ========================================================================== */
/*                             RAYCASTING                                     */
/* ========================================================================== */

int					ft_init_mlx(t_data *data);

#endif
