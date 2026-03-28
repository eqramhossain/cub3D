/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_texture_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 22:10:16 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/28 22:21:13 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_load_textures_to_mlx(t_data *data)
{
	int	width;
	int	height;

	width = WALL_SIZE;
	height = WALL_SIZE;
	data->texture->tex_helper->no_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture->no_texture, &width, &height);
	if (!data->texture->tex_helper->no_wall)
		return (ft_error("failed to load NO texture"), ERROR);
	data->texture->tex_helper->so_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture->so_texture, &width, &height);
	if (!data->texture->tex_helper->so_wall)
		return (ft_error("failed to load SO texture"), ERROR);
	data->texture->tex_helper->we_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture->we_texture, &width, &height);
	if (!data->texture->tex_helper->we_wall)
		return (ft_error("failed to load WE texture"), ERROR);
	data->texture->tex_helper->ea_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture->ea_texture, &width, &height);
	if (!data->texture->tex_helper->ea_wall)
		return (ft_error("failed to load EA texture"), ERROR);
	return (SUCCESS);
}

static int	ft_load_addr(t_texture *texture)
{
	texture->tex_helper->no_addr = mlx_get_data_addr(texture->tex_helper->no_wall,
			&texture->tex_helper->no_bpp, &texture->tex_helper->no_line_len,
			&texture->tex_helper->no_end);
	if (!texture->tex_helper->no_addr)
		return (ft_error("failed to get NO texture address"), ERROR);
	texture->tex_helper->so_addr = mlx_get_data_addr(texture->tex_helper->so_wall,
			&texture->tex_helper->so_bpp, &texture->tex_helper->so_line_len,
			&texture->tex_helper->so_end);
	if (!texture->tex_helper->so_addr)
		return (ft_error("failed to get SO texture address"), ERROR);
	texture->tex_helper->we_addr = mlx_get_data_addr(texture->tex_helper->we_wall,
			&texture->tex_helper->we_bpp, &texture->tex_helper->we_line_len,
			&texture->tex_helper->we_end);
	if (!texture->tex_helper->we_addr)
		return (ft_error("failed to get WE texture address"), ERROR);
	texture->tex_helper->ea_addr = mlx_get_data_addr(texture->tex_helper->ea_wall,
			&texture->tex_helper->ea_bpp, &texture->tex_helper->ea_line_len,
			&texture->tex_helper->ea_end);
	if (!texture->tex_helper->ea_addr)
		return (ft_error("failed to get EA texture address"), ERROR);
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
	if (ft_load_addr(data->texture) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
