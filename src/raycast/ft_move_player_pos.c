/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:36:35 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/29 12:45:19 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x + data->player->dir_x * MOVE_SPEED;
	new_y = data->player->pos_y + data->player->dir_y * MOVE_SPEED;
	return (ft_is_a_valid_move(data, new_x, new_y));
}

static int	ft_move_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x - data->player->dir_x * MOVE_SPEED;
	new_y = data->player->pos_y - data->player->dir_y * MOVE_SPEED;
	return (ft_is_a_valid_move(data, new_x, new_y));
}

static int	ft_move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x - data->player->plane_x * MOVE_SPEED;
	new_y = data->player->pos_y - data->player->plane_y * MOVE_SPEED;
	return (ft_is_a_valid_move(data, new_x, new_y));
}

static int	ft_move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x + data->player->plane_x * MOVE_SPEED;
	new_y = data->player->pos_y + data->player->plane_y * MOVE_SPEED;
	return (ft_is_a_valid_move(data, new_x, new_y));
}

int	ft_move_player_pos(t_data *data)
{
	int	player_moved;

	player_moved = 0;
	if (data->player->move_y == 1)
		player_moved += ft_move_forward(data);
	if (data->player->move_y == -1)
		player_moved += ft_move_backward(data);
	if (data->player->move_x == -1)
		player_moved += ft_move_left(data);
	if (data->player->move_x == 1)
		player_moved += ft_move_right(data);
	if (data->player->rotate != 0)
		player_moved += ft_rotate_player(data, data->player->rotate);
	return (player_moved);
}
