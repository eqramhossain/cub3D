/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster_engine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:44:00 by ehossain          #+#    #+#             */
/*   Updated: 2026/04/07 11:45:51 by ekram            ###   ########.fr       */
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
	int				tex_width;
	int				tex_height;

	color = 0;
	ft_draw_ceiling(data, ray, col);
	ft_get_textures_info(ray, data, &addr, &line_len);
	if (ray->side == 0 && ray->raydir_x > 0)
	{
		tex_width = data->texture->ea_width;
		tex_height = data->texture->ea_height;
	}
	if (ray->side == 0 && ray->raydir_x < 0)
	{
		tex_width = data->texture->we_width;
		tex_height = data->texture->we_height;
	}
	if (ray->side == 1 && ray->raydir_y > 0)
	{
		tex_width = data->texture->so_width;
		tex_height = data->texture->so_height;
	}
	if (ray->side == 1 && ray->raydir_y < 0)
	{
		tex_width = data->texture->no_width;
		tex_height = data->texture->no_height;
	}
	ray->step = 1.0 * tex_height / ray->line_height;
	ray->tex_pos = (ray->draw_start - data->win_height / 2 + ray->line_height
			/ 2) * ray->step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (tex_height - 1);
		ray->tex_pos = ray->tex_pos + ray->step;
		color = *(unsigned int *)(addr + (ray->tex_y * line_len + ray->tex_x
					* (data->texture->tex_helper->no_bpp / 8)));
		ft_mlx_pixel_put(data, col, y, color);
		y++;
	}
	ft_draw_floor(data, ray, col);
}

void    ft_set_texture_dimensions(t_ray *ray, t_data *data)
{
    if (ray->side == 0 && ray->raydir_x > 0)
    {
        ray->tex_width = data->texture->tex_helper->ea_width;
        ray->tex_height = data->texture->tex_helper->ea_height;
    }
    else if (ray->side == 0 && ray->raydir_x < 0)
    {
        ray->tex_width = data->texture->tex_helper->we_width;
        ray->tex_height = data->texture->tex_helper->we_height;
    }
    else if (ray->side == 1 && ray->raydir_y > 0)
    {
        ray->tex_width = data->texture->tex_helper->so_width;
        ray->tex_height = data->texture->tex_helper->so_height;
    }
    else if (ray->side == 1 && ray->raydir_y < 0)
    {
        ray->tex_width = data->texture->tex_helper->no_width;
        ray->tex_height = data->texture->tex_helper->no_height;
    }
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

		ft_get_textures_info(&ray, data, &ray->tex_addr, &ray->tex_line_len);
        ft_set_texture_dimensions(&ray, data); 

		ft_calculate_texture(&ray, data);
		ft_raycast_texture_walls(&ray, data, col);
		col++;
	}
	return (SUCCESS);
}
