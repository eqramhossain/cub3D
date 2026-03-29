/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster_engine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:44:00 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/29 15:49:06 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dda_algorithm(t_ray *ray, t_data *data)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player->pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player->pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player->pos_y)
			* ray->delta_dist_y;
	}
}

void	ft_dda_algorithm_helper(t_ray *ray, t_data *data)
{
	ray->hit = 0;
	ray->side = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_y >= data->map_height || ray->map_x < 0
			|| ray->map_x >= data->map_width)
		{
			ray->hit = 1;
			break ;
		}
		if (data->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	ft_calculate_height(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
	if (ray->wall_dist <= 0.000001)
		ray->wall_dist = 0.000001;
	ray->line_height = (int)(data->win_height / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_end >= data->win_height)
		ray->draw_end = data->win_height - 1;
}

void	ft_raycast_texture_walls(t_ray *ray, t_data *data, int col)
{
	unsigned int	color;
	int				y;
	int				line_len;
	char			*addr;

	color = 0;
	ft_draw_ceiling(data, ray, col);
	ft_get_textures_info(ray, data, &addr, &line_len);
	ray->step = 1.0 * WALL_SIZE / ray->line_height;
	ray->tex_pos = (ray->draw_start - data->win_height / 2 + ray->line_height
			/ 2) * ray->step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (WALL_SIZE - 1);
		ray->tex_pos = ray->tex_pos + ray->step;
		color = *(unsigned int *)(addr + (ray->tex_y * line_len + ray->tex_x
					* (data->texture->tex_helper->no_bpp / 8)));
		ft_mlx_pixel_put(data, col, y, color);
		y++;
	}
	ft_draw_floor(data, ray, col);
}

int	ft_raycaster_engine(t_data *data)
{
	t_ray	ray;
	int		col;

	col = 0;
	while (col < data->win_width)
	{
		ft_initialize_raycaster_engine(col, &ray, data);
		ft_dda_algorithm(&ray, data);
		ft_dda_algorithm_helper(&ray, data);
		ft_calculate_height(&ray, data);
		ft_raycast_texture_walls(&ray, data, col);
		col++;
	}
	return (SUCCESS);
}
