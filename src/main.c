/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:44:15 by egerin            #+#    #+#             */
/*   Updated: 2025/11/15 18:49:44 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_data *data, t_textures *textures, t_player *player)
{
	if (!check_map_file(data, textures))
	{
		free_tab(data->map);
		free_textures(textures);
		exit(1);
	}
	if (!get_location(data, player))
	{
		free_tab(data->map);
		free_textures(textures);
		exit(1);
	}
	printf("get_location : player->x = %lf\nget_location : player->y = %lf\n", player->x, player->y);
}

int	on_destroy(t_data *data)
{
	free_tab(data->map);
	free_textures(data->textures);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		on_destroy(data);
	return (1);
}

void	init_mlx(t_data *data)
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
	t_data	data;
	t_textures	textures;
	t_player	player;
	char	*tmp;

	ft_memset(&data, 0, sizeof(t_data));
	ft_memset(&player, 0, sizeof(t_player));
	init_textures(&textures);
	data.textures = &textures;
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
	parsing(&data, &textures, &player);
	init_mlx(&data);
	return (0);
}
