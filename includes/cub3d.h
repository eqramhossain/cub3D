/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:21 by egerin            #+#    #+#             */
/*   Updated: 2025/11/08 15:59:10 by egerin           ###   ########.fr       */
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

typedef	struct s_map
{
	char	**map;
	int		tab[6];
}	t_map;

/* PARSING */
int		check_file_extension(char *str, char *extension);
int		check_map_file(t_map *data);
char	*read_map(char *file);

#endif
