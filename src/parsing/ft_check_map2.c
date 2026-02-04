/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:12:45 by ehossain          #+#    #+#             */
/*   Updated: 2026/02/04 16:49:35 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_all_one(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ERROR);
	while (str[i])
	{
		if (str[i] != '1')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

static int	ft_up_bottom_check(t_data *data)
{
	int	i;
	int	line;
	int	line_len[2];

	i = 0;
	line = 0;
	while (data->map[i])
	{
		line++;
		i++;
	}
	if (line == 2)
		return (ERROR);
	line_len[0] = ft_strlen(data->map[0]);
	line_len[1] = ft_strlen(data->map[line - 1]);
	if (ft_all_one(data->map[0]) == ERROR)
		return (ERROR);
	if (ft_all_one(data->map[line - 1]) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int	ft_side_check(t_data *data)
{
	int	i;
	int	line_len;

	i = 0;
	while (data->map[i])
	{
		line_len = ft_strlen(data->map[i]);
		if (data->map[i][0] != '1' || data->map[i][line_len - 1] != '1')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	ft_map_closed(t_data *data)
{
	if (ft_up_bottom_check(data) == ERROR)
		return (ERROR);
	if (ft_side_check(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
