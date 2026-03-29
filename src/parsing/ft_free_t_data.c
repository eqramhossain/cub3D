/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:02:48 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/29 15:21:16 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_file_content(char **file_content)
{
	int	i;

	i = 0;
	if (!file_content)
		return ;
	while (file_content[i])
	{
		if (file_content[i])
			free(file_content[i]);
		i++;
	}
	free(file_content);
}

void	ft_free_texture(t_data *data)
{
	if (!data->texture || !data->texture->tex_helper)
		return ;
	if (data->texture->tex_helper->no_wall)
		mlx_destroy_image(data->mlx_ptr, data->texture->tex_helper->no_wall);
	if (data->texture->tex_helper->so_wall)
		mlx_destroy_image(data->mlx_ptr, data->texture->tex_helper->so_wall);
	if (data->texture->tex_helper->ea_wall)
		mlx_destroy_image(data->mlx_ptr, data->texture->tex_helper->ea_wall);
	if (data->texture->tex_helper->we_wall)
		mlx_destroy_image(data->mlx_ptr, data->texture->tex_helper->we_wall);
}

void	ft_free_texture_path(t_data *data)
{
	if (!data->texture)
		return ;
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
	if (data->mlx_ptr)
		mlx_loop_end(data->mlx_ptr);
	if (data->file_content)
		ft_free_file_content(data->file_content);
	if (data->map)
		ft_free_file_content(data->map); // map content
	ft_free_texture_path(data);
	ft_free_texture(data);
	if (data->texture->tex_helper)
		free(data->texture->tex_helper);
	//
	if (data->texture)
		free(data->texture);
	//
	if (data->img->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	if (data->img)
		free(data->img);
	//
	if (data->player)
		free(data->player);
	//
	if (data->ray)
		free(data->ray);
	if (data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
}
