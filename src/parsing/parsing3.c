/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:12:29 by egerin            #+#    #+#             */
/*   Updated: 2025/11/19 13:17:17 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_file(t_data *data, t_textures *textures)
{
	if (!check_textures(data, "NO", 2) || !check_textures(data, "SO", 2)
		|| !check_textures(data, "WE", 2) || !check_textures(data, "EA", 2)
		|| !check_textures(data, "F", 1) || !check_textures(data, "C", 1)
		|| !store_textures(data, textures) || !store_rgb(data, textures)
		|| !check_rgb(textures) || !check_walls(data))
		return (0);
	printf("%s\n", textures->no);
	printf("%s\n", textures->so);
	printf("%s\n", textures->we);
	printf("%s\n", textures->ea);
	printf("%d\n", textures->floor_tab[0]);
	printf("%d\n", textures->floor_tab[1]);
	printf("%d\n", textures->floor_tab[2]);
	printf("%d\n", textures->ceiling_tab[0]);
	printf("%d\n", textures->ceiling_tab[1]);
	printf("%d\n", textures->ceiling_tab[2]);
	printf("ci bon\n");
	return (1);
}
