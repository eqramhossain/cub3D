/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture_flag.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:06:56 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/28 14:44:13 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_count_texture_flag(char **file_content, char *flag)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (file_content[i])
	{
		j = 0;
		while (file_content[i][j] == ' ' || file_content[i][j] == '\t')
			j++;
		if (ft_strncmp(&file_content[i][j], flag, 2) == 0)
		{
			if (file_content[i][j + 2] == ' ' || file_content[i][j + 2] == '\t')
			{
				count++;
			}
		}
		i++;
	}
	return (count);
}

int	ft_check_all_texture_flag(t_data *data)
{
	int	no_count;
	int	so_count;
	int	ea_count;
	int	we_count;

	no_count = ft_count_texture_flag(data->file_content, "NO");
	so_count = ft_count_texture_flag(data->file_content, "SO");
	ea_count = ft_count_texture_flag(data->file_content, "EA");
	we_count = ft_count_texture_flag(data->file_content, "WE");
	if (no_count != 1)
		return (ft_error("NO flag must appear exactly once"), ERROR);
	if (so_count != 1)
		return (ft_error("SO flag must appear exactly once"), ERROR);
	if (ea_count != 1)
		return (ft_error("EA flag must appear exactly once"), ERROR);
	if (we_count != 1)
		return (ft_error("WE flag must appear exactly once"), ERROR);
	return (SUCCESS);
}
