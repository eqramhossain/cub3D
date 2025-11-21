/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:44:15 by egerin            #+#    #+#             */
/*   Updated: 2025/11/21 14:26:23 by ehossain         ###   ########.fr       */
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
	if (!get_location(data, player) || !get_angle(data, player))
	{
		free_tab(data->map);
		free_textures(textures);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	t_textures	textures;
	t_player	player;
	char		*tmp;

	ft_memset(&data, 0, sizeof(t_data));
	ft_memset(&player, 0, sizeof(t_player));
	init_textures(&textures);
	data.textures = &textures;
	if (ac != 2)
		return (ft_error("usage : ./cub3d [map name]"), 1);
	if (!check_file_extension(av[1], ".cub"))
		return (ft_error("only .cub files"), 1);
	tmp = read_map(av[1]);
	data.map = ft_split(tmp, '\n');
	free(tmp);
	parsing(&data, &textures, &player);
	ft_get_parsed_data(&data, &player, &textures);
	return (0);
}
