/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_texture_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 22:10:16 by ehossain          #+#    #+#             */
/*   Updated: 2026/04/09 09:04:16 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_load_textures_to_mlx(t_data *data)
{
	data->texture->tex_helper->no_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture->no_texture, &data->texture->tex_helper->no_width,
			&data->texture->tex_helper->no_height);
	if (!data->texture->tex_helper->no_wall)
		return (ft_error("failed to load NO texture"), ERROR);
	data->texture->tex_helper->so_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture->so_texture, &data->texture->tex_helper->so_width,
			&data->texture->tex_helper->so_height);
	if (!data->texture->tex_helper->so_wall)
		return (ft_error("failed to load SO texture"), ERROR);
	data->texture->tex_helper->we_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture->we_texture, &data->texture->tex_helper->we_width,
			&data->texture->tex_helper->we_height);
	if (!data->texture->tex_helper->we_wall)
		return (ft_error("failed to load WE texture"), ERROR);
	data->texture->tex_helper->ea_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->texture->ea_texture, &data->texture->tex_helper->ea_width,
			&data->texture->tex_helper->ea_height);
	if (!data->texture->tex_helper->ea_wall)
		return (ft_error("failed to load EA texture"), ERROR);
	return (SUCCESS);
}

static int	ft_load_addr(t_tex_helper *tex_helper)
{
	tex_helper->no_addr = mlx_get_data_addr(tex_helper->no_wall,
			&tex_helper->no_bpp, &tex_helper->no_line_len, &tex_helper->no_end);
	if (!tex_helper->no_addr)
		return (ft_error("failed to get NO texture address"), ERROR);
	tex_helper->so_addr = mlx_get_data_addr(tex_helper->so_wall,
			&tex_helper->so_bpp, &tex_helper->so_line_len, &tex_helper->so_end);
	if (!tex_helper->so_addr)
		return (ft_error("failed to get SO texture address"), ERROR);
	tex_helper->we_addr = mlx_get_data_addr(tex_helper->we_wall,
			&tex_helper->we_bpp, &tex_helper->we_line_len, &tex_helper->we_end);
	if (!tex_helper->we_addr)
		return (ft_error("failed to get WE texture address"), ERROR);
	tex_helper->ea_addr = mlx_get_data_addr(tex_helper->ea_wall,
			&tex_helper->ea_bpp, &tex_helper->ea_line_len, &tex_helper->ea_end);
	if (!tex_helper->ea_addr)
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
	if (ft_load_addr(data->texture->tex_helper) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
