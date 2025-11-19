/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:13:16 by egerin            #+#    #+#             */
/*   Updated: 2025/11/19 17:28:42 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_location(t_data *data, t_player *player)
{
	int	i;
	int	j;

	i = data->map_start;
	while (i <= data->map_end)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				player->x = i;
				player->y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	get_angle(t_data *data, t_player *player)
{
	if (data->map[(int)player->x][(int)player->y] == 'N')
	{
		player->angle = 0;
		return (1);
	}
	else if (data->map[(int)player->x][(int)player->y] == 'E')
	{
		player->angle = 90;
		return (1);
	}
	else if (data->map[(int)player->x][(int)player->y] == 'S')
	{
		player->angle = 180;
		return (1);
	}
	else if (data->map[(int)player->x][(int)player->y] == 'W')
	{
		player->angle = 270;
		return (1);
	}
	return (0);
}
