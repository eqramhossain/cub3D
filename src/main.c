/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:44:15 by egerin            #+#    #+#             */
/*   Updated: 2025/11/13 17:05:19 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_map *data, t_textures *textures)
{
	if (!check_map_file(data, textures))
	{
		free_tab(data->map);
		free_textures(textures);
		exit(1);
	}
}

int	on_destroy(t_map *data)
{
	free_tab(data->map);
	free_textures(data->textures);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
}

int	on_keypress(int keysym, t_map *data)
{
	if (keysym == XK_Escape)
		on_destroy(data);
	return (1);
}

void	init_mlx(t_map *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1080, 720, "cub3d");
	if (!data->win_ptr)
		free(data->mlx_ptr);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, data);
	mlx_loop(data->mlx_ptr);
	free(data->win_ptr);
}

int	main(int ac, char **av)
{
	t_map	data;
	t_textures	textures;
	char	*tmp;

	ft_memset(&data, 0, sizeof(t_map));
	init_textures(&textures, &data);
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
	parsing(&data, &textures);
	init_mlx(&data);
	return (0);
}
