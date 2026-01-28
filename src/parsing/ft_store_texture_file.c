/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_texture_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 22:10:16 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/28 22:18:44 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_load_textures_to_mlx(t_data *data)
{
	int	width;
	int	height;

	data->texture->tex_helper.no_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture->no_texture, &width, &height);
	if (!data->texture->tex_helper.no_wall)
		return (ft_error("failed to load NO texture"), ERROR);
	data->texture->tex_helper.so_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture->so_texture, &width, &height);
	if (!data->texture->tex_helper.so_wall)
		return (ft_error("failed to load SO texture"), ERROR);
	data->texture->tex_helper.we_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture->we_texture, &width, &height);
	if (!data->texture->tex_helper.we_wall)
		return (ft_error("failed to load WE texture"), ERROR);
	data->texture->tex_helper.ea_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture->ea_texture, &width, &height);
	if (!data->texture->tex_helper.ea_wall)
		return (ft_error("failed to load EA texture"), ERROR);
	return (SUCCESS);
}

int	ft_store_all_texture_file(t_data *data)
{
	char	*line;

	line = ft_find_texture_line(data->file_content, "NO");
	data->texture->no_texture = ft_extract_texture_path(line, "NO");
	line = ft_find_texture_line(data->file_content, "SO");
	data->texture->so_texture = ft_extract_texture_path(line, "SO");
	line = ft_find_texture_line(data->file_content, "EA");
	data->texture->ea_texture = ft_extract_texture_path(line, "EA");
	line = ft_find_texture_line(data->file_content, "WE");
	data->texture->we_texture = ft_extract_texture_path(line, "WE");
	if (ft_load_textures_to_mlx(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
