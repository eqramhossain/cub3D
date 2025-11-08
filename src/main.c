/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:44:15 by egerin            #+#    #+#             */
/*   Updated: 2025/11/08 16:02:46 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_map *data)
{
	if (!check_map_file(data))
	{
		// destroy_all();
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_map	data;
	if (ac != 2)
	{
		write (2, "usage : ./cub3d [map name]\n", 27);
		return(0);
	}
	if (!check_file_extension(av[1], ".cub"))
		return (write(2, "only .cub files\n", 16), 0);
	data.map = ft_split(read_map(av[1]), '\n');
	parsing(&data);
	for (int i = 0; data.map[i]; i++)
		printf("%s\n", data.map[i]);
}
