/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_player_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:07:06 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/29 13:41:43 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_player_dir_north_south(t_data *data)
{
	if (data->player->dir_char == 'N')
	{
		data->player->dir_x = 0;
		data->player->dir_y = -1;
		data->player->plane_x = 0.66;
		data->player->plane_y = 0;
	}
	if (data->player->dir_char == 'S')
	{
		data->player->dir_x = 0;
		data->player->dir_y = 1;
		data->player->plane_x = -0.66;
		data->player->plane_y = 0;
	}
}

static void	ft_init_player_dir_east_west(t_data *data)
{
	if (data->player->dir_char == 'E')
	{
		data->player->dir_x = 1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = 0.66;
	}
	if (data->player->dir_char == 'W')
	{
		data->player->dir_x = -1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = -0.66;
	}
}

static void	ft_init_player_dir(t_data *data)
{
	if (data->player->dir_char == 'N' || data->player->dir_char == 'S')
		ft_init_player_dir_north_south(data);
	if (data->player->dir_char == 'E' || data->player->dir_char == 'W')
		ft_init_player_dir_east_west(data);
	data->player->move_x = 0;
	data->player->move_y = 0;
	data->player->rotate = 0;
	data->player->has_moved = 0;
}

int	ft_extract_player_info(t_data *data)
{
	if (ft_find_player_pos(data) == ERROR)
		return (ERROR);
	ft_init_player_dir(data);
	return (SUCCESS);
}
