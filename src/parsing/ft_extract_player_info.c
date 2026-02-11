/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_player_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:07:06 by ehossain          #+#    #+#             */
/*   Updated: 2026/02/11 10:17:04 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_find_player_pos(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if ((data->map[i][j] == 'N') || (data->map[i][j] == 'S')
				|| (data->map[i][j] == 'E') || (data->map[i][j] == 'W'))
			{
				data->player->dir_char = data->map[i][j];
				data->player->pos_x = j + 0.5;
				data->player->pos_y = i + 0.5;
				count++;
			}
			else if (count > 1)
				return (ft_error("player must only appear once"), ERROR);
			j++;
		}
		i++;
	}
	if (count == 0)
		return (ft_error("player not found"), ERROR);
	return (SUCCESS);
}

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
	data->player->move_x = -1;
	data->player->move_y = -1;
	data->player->rotate = -1;
	data->player->has_moved = -1;
}

int	ft_extract_player_info(t_data *data)
{
	if (ft_find_player_pos(data) == ERROR)
		return (ERROR);
	ft_init_player_dir(data);
	return (SUCCESS);
}
