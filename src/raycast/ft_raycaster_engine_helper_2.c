/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster_engine_helper_2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:47:14 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/29 15:49:03 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calculate_texture(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		ray->wall_x = data->player->pos_y + ray->wall_dist * ray->raydir_y;
	else
		ray->wall_x = data->player->pos_x + ray->wall_dist * ray->raydir_x;
	ray->wall_x = ray->wall_x - floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)(WALL_SIZE));
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = WALL_SIZE - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = WALL_SIZE - ray->tex_x - 1;
}

void	ft_get_textures_info(t_ray *ray, t_data *data, char **addr,
		int *line_len)
{
	if (ray->side == 0 && ray->raydir_x > 0)
	{
		*addr = data->texture->tex_helper->ea_addr;
		*line_len = data->texture->tex_helper->ea_line_len;
	}
	else if (ray->side == 0 && ray->raydir_x < 0)
	{
		*addr = data->texture->tex_helper->we_addr;
		*line_len = data->texture->tex_helper->we_line_len;
	}
	else if (ray->side == 1 && ray->raydir_y > 0)
	{
		*addr = data->texture->tex_helper->so_addr;
		*line_len = data->texture->tex_helper->so_line_len;
	}
	else if (ray->side == 1 && ray->raydir_y < 0)
	{
		*addr = data->texture->tex_helper->no_addr;
		*line_len = data->texture->tex_helper->no_line_len;
	}
}

void	ft_initialize_raycaster_engine(int col, t_ray *ray, t_data *data)
{
	ft_initialize_t_ray(ray);
	ray->map_x = (int)data->player->pos_x;
	ray->map_y = (int)data->player->pos_y;
	ray->camera = 2 * col / (double)data->win_width - 1;
	ray->raydir_x = data->player->dir_x + data->player->plane_x * ray->camera;
	ray->raydir_y = data->player->dir_y + data->player->plane_y * ray->camera;
	if (ray->raydir_x == 0.0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->raydir_x);
	if (ray->raydir_y == 0.0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->raydir_y);
}
