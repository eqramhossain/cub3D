/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:09:21 by egerin            #+#    #+#             */
/*   Updated: 2025/11/18 18:10:36 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_map_start_strcmp(char *trim)
{
	if (ft_strncmp(trim, "NO ", 3) == 0 || ft_strncmp(trim, "SO ", 3) == 0 || 
		ft_strncmp(trim, "WE ", 3) == 0 || ft_strncmp(trim, "EA ", 3) == 0 ||
		ft_strncmp(trim, "F ", 2) == 0 || ft_strncmp(trim, "C ", 2) == 0)
		return (1);
	return (0);
}

int	find_map_start(t_data *data)
{
	int		i;
	char	*trim;

	i = 0;
	while (data->map[i])
	{
		trim = ft_strtrim(data->map[i], " \t\n");
		if (find_map_start_strcmp(trim) == 1)
		{
			free(trim);
			i++;
			continue ;
		}
		if (ft_strlen(trim) == 0)
		{
			free(trim);
			i++;
			continue ;
		}
		if (is_map_line(trim))
			return (free(trim), i);
		free(trim);
		i++;
	}
	return (0);
}

int	check_walls_helper(t_data *data, char *trim, int *j, int i)
{
	if (i == data->map_start || i == data->map_end)
	{
		(*j) = 0;
		while (trim[(*j)])
		{
			if (trim[(*j)] != '1' && trim[(*j)] != ' ')
				return (0);
			(*j)++;
		}
	}
	else
	{
		if ((trim[0] != '1' && trim[0] != ' ') || (trim[ft_strlen(trim)
				- 1] != '1' && trim[ft_strlen(trim) - 1] != ' '))
			return (0);
	}
	return (1);
}

int	find_map_end(t_data *data)
{
	data->map_start = find_map_start(data);
	data->map_end = data->map_start;
	while (data->map[data->map_end])
	{
		if (!is_map_line2(data->map[data->map_end], data))
			return (0);
		data->map_end++;
	}
	data->map_end--;
	return (1);
}
