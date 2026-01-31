/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:12:01 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/31 21:55:10 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

// int	ft_extract_map(t_data *data)
// {
// }
