/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:21 by egerin            #+#    #+#             */
/*   Updated: 2025/11/21 16:16:34 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef width_win
#  define widht_win 1080
# endif

# ifndef height_win
#  define height_win 720
# endif

# define NO_SPRITE "./textures/xpm/NO.xpm"
# define SO_SPRITE "./textures/xpm/SO.xpm"
# define WE_SPRITE "./textures/xpm/WE.xpm"
# define EA_SPRITE "./textures/xpm/EA.xpm"

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_textures
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*no_sprite;
	char		*so_sprite;
	char		*we_sprite;
	char		*ea_sprite;
	int			floor;
	int			ceiling;
	int			floor_tab[3];
	int			ceiling_tab[3];
}				t_textures;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			angle;
}				t_player;

typedef struct s_data
{
	int			tmp;
	int			width;
	int			height;
	int			map_end;
	int			map_start;
	int			player_row;
	int			player_col;
	char		**map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_textures	*textures;
}				t_data;

/* PARSING */
int				check_file_extension(char *str, char *extension);
int				check_map_file(t_data *data, t_textures *textures);
int				check_textures(t_data *data, char *flag, int j);
int				store_textures(t_data *data, t_textures *textures);
int				store_rgb(t_data *data, t_textures *textures);
int				check_walls(t_data *data);
int				check_rgb(t_textures *textures);
char			*read_map(char *file);

/* UTILS */
void			free_tab(char **tab);
void			init_textures(t_textures *textures);
void			free_textures(t_textures *textures);
int				is_map_line(char *line);
void			copy_textures(t_textures *textures, char **tab, int i);
int				is_map_line2(char *line, t_data *data);
int				line_matches_flag(char *trim, char *flag, int j);
int				count_unique_flag(t_data *data, char *flag, int j);
void			store_textures_loop(char *trim, t_textures *textures, int *j);
void			store_rgb_condition(t_textures *textures, char *trim, int *j);
int				find_map_start_strcmp(char *trim);
int				find_map_start(t_data *data);
int				check_walls_helper(t_data *data, char *trim, int *j, int i);
int				find_map_end(t_data *data);
void			ft_error(char *error_msg);
int				ft_create_color(int r, int g, int b);

/* POSITION */
int				get_location(t_data *data, t_player *player);
int				get_angle(t_data *data, t_player *player);

/* ========================================================================== */
/*                             RAYCASTING                                     */
/* ========================================================================== */

void			ft_get_parsed_data(t_data *data, t_player *player,
					t_textures *textures);
void			ft_handle_mlx(t_data *data);
void			ft_init_mlx(t_data *data);

#endif
