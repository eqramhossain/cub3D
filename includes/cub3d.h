/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:21 by egerin            #+#    #+#             */
/*   Updated: 2025/11/11 16:37:47 by egerin           ###   ########.fr       */
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

typedef	struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx ;

typedef struct s_textures
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		floor_tab[3];
	int		ceiling_tab[3];
	t_mlx	*mlx;
}	t_textures;

typedef	struct s_map
{
	char		**map;
	int			tab[6];
	t_textures	*textures;
}	t_map;

/* PARSING */
int		check_file_extension(char *str, char *extension);
int		check_map_file(t_map *data, t_textures *textures, t_mlx *mlx);
char	*read_map(char *file);

/* UTILS */
void	free_tab(char **tab);
void	init_textures(t_textures *textures);
void	free_textures(t_textures *textures);
int		is_map_line(char *line);
void	copy_textures(t_textures *textures, char **tab, int i);

#endif
