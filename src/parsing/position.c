/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:13:16 by egerin            #+#    #+#             */
/*   Updated: 2025/11/17 20:15:13 by ehossain         ###   ########.fr       */
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
