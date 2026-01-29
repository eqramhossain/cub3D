/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:02:48 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/29 19:54:22 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_file_content(char **file_content)
{
	int	i;

	i = 0;
	while (file_content[i])
	{
		free(file_content[i]);
		i++;
	}
	free(file_content);
}

void	ft_free_texture(t_data *data)
{
	if (data->texture->tex_helper.no_wall)
		mlx_destroy_image(data->mlx_ptr, data->texture->tex_helper.no_wall);
	if (data->texture->tex_helper.so_wall)
		mlx_destroy_image(data->mlx_ptr, data->texture->tex_helper.so_wall);
	if (data->texture->tex_helper.ea_wall)
		mlx_destroy_image(data->mlx_ptr, data->texture->tex_helper.ea_wall);
	if (data->texture->tex_helper.we_wall)
		mlx_destroy_image(data->mlx_ptr, data->texture->tex_helper.we_wall);
}

void	ft_free_texture_path(t_data *data)
{
	if (data->texture->no_texture)
		free(data->texture->no_texture);
	if (data->texture->so_texture)
		free(data->texture->so_texture);
	if (data->texture->ea_texture)
		free(data->texture->ea_texture);
	if (data->texture->we_texture)
		free(data->texture->we_texture);
}

void	ft_free_t_data(t_data *data)
{
	ft_free_file_content(data->file_content);
	ft_free_texture_path(data);
	ft_free_texture(data);
	free(data->texture);
	free(data->img);
	free(data->player);
	free(data->ray);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
