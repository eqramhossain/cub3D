/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:21 by egerin            #+#    #+#             */
/*   Updated: 2025/11/15 18:46:15 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_textures
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	void	*NO_sprite;
	void	*SO_sprite;
	void	*WE_sprite;
	void	*EA_sprite;
	int		floor_tab[3];
	int		ceiling_tab[3];
}	t_textures;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef	struct s_data
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
}	t_data;

/* PARSING */
int		check_file_extension(char *str, char *extension);
int		check_map_file(t_data *data, t_textures *textures);
char	*read_map(char *file);

/* UTILS */
void	free_tab(char **tab);
void	init_textures(t_textures *textures);
void	free_textures(t_textures *textures);
int		is_map_line(char *line);
void	copy_textures(t_textures *textures, char **tab, int i);
int		is_map_line2(char *line, t_data *data);

/* POSITION */
int		get_location(t_data *data, t_player *player);

#endif
