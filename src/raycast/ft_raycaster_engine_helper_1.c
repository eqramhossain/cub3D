/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster_engine_helper_1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:44:34 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/29 15:45:50 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_height)
	{
		dst = data->img->addr + (y * data->img->line_len + x * (data->img->bpp
					/ 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_draw_vertical_line(t_data *data, int x, t_var *var, int color)
{
	int	y;

	y = var->start;
	while (y <= var->end)
	{
		ft_mlx_pixel_put(data, x, y, color);
		y++;
	}
}

void	ft_draw_ceiling(t_data *data, t_ray *ray, int col)
{
	t_var	var;

	var.start = 0;
	var.end = ray->draw_start - 1;
	ft_draw_vertical_line(data, col, &var, data->texture->ceiling);
}

void	ft_draw_floor(t_data *data, t_ray *ray, int col)
{
	t_var	var;

	var.start = ray->draw_end + 1;
	var.end = data->win_height - 1;
	ft_draw_vertical_line(data, col, &var, data->texture->floor);
}

void	ft_initialize_t_ray(t_ray *ray)
{
	ray->camera = 0;
	ray->raydir_x = 0;
	ray->raydir_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->wall_dist = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->color = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->wall_x = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
	ray->step = 0;
	ray->tex_pos = 0;
}
