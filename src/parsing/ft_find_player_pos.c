/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:41:16 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/29 14:28:20 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_condition_check(t_data *data, int i, int j)
{
	if ((data->map[i][j] == 'N') || (data->map[i][j] == 'S')
		|| (data->map[i][j] == 'E') || (data->map[i][j] == 'W'))
		return (SUCCESS);
	return (ERROR);
}

static void	ft_update(t_data *data, int i, int j)
{
	data->player->dir_char = data->map[i][j];
	data->player->pos_x = j + 0.5;
	data->player->pos_y = i + 0.5;
}

static void	ft_init(int *i, int *count)
{
	*i = 0;
	*count = 0;
}

int	ft_find_player_pos(t_data *data)
{
	int	i;
	int	j;
	int	count;

	ft_init(&i, &count);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_condition_check(data, i, j) == SUCCESS)
			{
				ft_update(data, i, j);
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
