/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:47:19 by egerin            #+#    #+#             */
/*   Updated: 2025/11/21 18:03:45 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_sprite(void *sprite, t_data *data)
{
	if (!sprite)
	{
		ft_printf("Error\ngenerating sprites mlx_xpm_file_to_image failed");
		exit(1);
	}
}

void	generate_sprites(t_data *data, t_textures *textures)
{
	textures->no_sprite = mlx_xpm_file_to_image(data->mlx_ptr, NO_SPRITE,
			&data->width, &data->height);
	check_sprite(textures->no_sprite, data);
	textures->so_sprite = mlx_xpm_file_to_image(data->mlx_ptr, SO_SPRITE,
			&data->width, &data->height);
	check_sprite(textures->so_sprite, data);
	textures->we_sprite = mlx_xpm_file_to_image(data->mlx_ptr, WE_SPRITE,
			&data->width, &data->height);
	check_sprite(textures->we_sprite, data);
	textures->ea_sprite = mlx_xpm_file_to_image(data->mlx_ptr, EA_SPRITE,
			&data->width, &data->height);
	check_sprite(textures->ea_sprite, data);
}
