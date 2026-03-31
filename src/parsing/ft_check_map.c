/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:12:01 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/31 12:12:30 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map_char_valid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if ((data->map[i][j] != ' ') && (data->map[i][j] != '0')
				&& (data->map[i][j] != '1') && (data->map[i][j] != 'N')
				&& (data->map[i][j] != 'S') && (data->map[i][j] != 'E')
				&& (data->map[i][j] != 'W'))
				return (ERROR);
			if (data->map[i][j] == ' ')
				(data->map[i][j] = '1');
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	ft_find_flag(char *file_content, char *flag)
{
	int	i;
	int	len;

	len = ft_strlen(flag);
	i = 0;
	while (file_content[i])
	{
		while (file_content[i] == ' ' || file_content[i] == '\t')
			i++;
		if (ft_strncmp(&file_content[i], flag, len) == 0)
		{
			if (file_content[i + len] == ' ' || file_content[i + len] == '\t')
			{
				return (SUCCESS);
			}
		}
		i++;
	}
	return (ERROR);
}

int	ft_is_map_last(t_data *data)
{
	int	i;
	int	len;
	int	count;

	i = 0;
	len = 0;
	count = 0;
	while (data->file_content[len])
		len++;
	while (i < 6)
	{
		if ((ft_find_flag(data->file_content[i], "NO") == SUCCESS)
			|| (ft_find_flag(data->file_content[i], "SO") == SUCCESS)
			|| (ft_find_flag(data->file_content[i], "EA") == SUCCESS)
			|| (ft_find_flag(data->file_content[i], "WE") == SUCCESS)
			|| (ft_find_flag(data->file_content[i], "F") == SUCCESS)
			|| (ft_find_flag(data->file_content[i], "C") == SUCCESS))
		{
			count++;
		}
		if (i == 5 && count != 6)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	ft_extract_map(t_data *data)
{
	int	i;
	int	len;
	int	j;

	len = 0;
	while (data->file_content[len])
		len++;
	len = len - 6;
	data->map = ft_calloc(len + 1, sizeof(char *));
	if (!data->map)
		return (ERROR);
	j = 0;
	i = 6;
	if (data->file_content[i] == NULL && len == 0)
		return (ERROR);
	while (data->file_content[i])
	{
		data->map[j] = ft_strdup(data->file_content[i]);
		i++;
		j++;
	}
	data->map[j] = NULL;
	return (SUCCESS);
}
