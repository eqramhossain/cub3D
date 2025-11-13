/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:47:19 by egerin            #+#    #+#             */
/*   Updated: 2025/11/13 17:21:27 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_sprite(void *sprite, t_map *data)
{
	if (!sprite)
	{
		ft_printf("Error\nSprites not good\n");
		on_destroy(data);
	}
}

void	generate_sprites(t_map *data, t_textures *textures)
{
	textures->NO_sprite = mlx_xpm_file_to_image(data->mlx_ptr, textures->NO, &data->width, &data->height);
	check_sprite(textures->NO_sprite, data);
	textures->SO_sprite = mlx_xpm_file_to_image(data->mlx_ptr, textures->SO, &data->width, &data->height);
	check_sprite(textures->SO_sprite, data);
	textures->WE_sprite = mlx_xpm_file_to_image(data->mlx_ptr, textures->WE, &data->width, &data->height);
	check_sprite(textures->WE_sprite, data);
	textures->EA_sprite = mlx_xpm_file_to_image(data->mlx_ptr, textures->EA, &data->width, &data->height);
	check_sprite(textures->EA_sprite, data);
}
