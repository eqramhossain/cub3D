/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 09:16:24 by ehossain          #+#    #+#             */
/*   Updated: 2026/04/09 09:16:37 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		ft_calculate_texture(&ray, data);
		ft_raycast_texture_walls(&ray, data, col);
		col++;
	}
	return (SUCCESS);
}
