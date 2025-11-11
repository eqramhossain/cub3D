/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:44:15 by egerin            #+#    #+#             */
/*   Updated: 2025/11/11 17:02:29 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_map *data, t_textures *textures, t_mlx *mlx)
{
	if (!check_map_file(data, textures, mlx))
	{
		free_tab(data->map);
		free_textures(textures);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_map	data;
	t_mlx	mlx;
	t_textures	textures;
	char	*tmp;

	init_textures(&textures);
	ft_memset(&data, 0, sizeof(t_map));
	// mlx.mlx_ptr = mlx_init();
	if (ac != 2)
	{
		write (2, "usage : ./cub3d [map name]\n", 27);
		return(0);
	}
	if (!check_file_extension(av[1], ".cub"))
		return (write(2, "only .cub files\n", 16), 0);
	tmp = read_map(av[1]);
	data.map = ft_split(tmp, '\n');
	free(tmp);
	parsing(&data, &textures, &mlx);
	free_tab(data.map);
	free_textures(&textures);
	return (0);
}
