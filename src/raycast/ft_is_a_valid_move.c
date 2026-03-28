/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_a_valid_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 07:14:27 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/28 23:14:05 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_is_a_valid_position(t_data *data, double new_x, double new_y)
{
	char	cell;

	if (new_x < 0.25 || new_x >= data->map_width - 1.25)
		return (ERROR);
	if (new_y < 0.25 || new_y >= data->map_height)
		return (ERROR);
	cell = data->map[(int)new_y][(int)new_x];
	if (cell != '0' && cell != 'N' && cell != 'S' && cell != 'E' && cell != 'W')
		return (ERROR);
	return (SUCCESS);
}

int	ft_is_a_valid_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (ft_is_a_valid_position(data, new_x, new_y) == SUCCESS)
	{
		data->player->pos_x = new_x;
		moved = 1;
	}
	if (ft_is_a_valid_position(data, new_x, new_y) == SUCCESS)
	{
		data->player->pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
