/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:57:57 by egerin            #+#    #+#             */
/*   Updated: 2025/11/08 17:55:31 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures(t_map *data, char *flag, int j)
{
	char	*trim;
	int	i;

	i = 0;
	while (data->map[i])
	{
		trim = ft_strtrim(data->map[i], " \t\n");
		if (ft_strncmp(trim, flag, j) == 0 && check_file_extension(trim, ".xpm"))
		{
			if (data->tab[i] == 1)
				data->tab[i] = -1;
			data->tab[i] = 1;
			return (1);
		}
		printf("%s\n", trim);
		i++;
	}
	return (0);
}

int	check_map_file(t_map *data)
{
	int	i;

	check_textures(data, "NO", 2);
	check_textures(data, "SO", 2);
	check_textures(data, "WE", 2);
	check_textures(data, "EA", 2);
	check_textures(data, "F", 1);
	check_textures(data, "C", 1);
	i = 0;
	while (i < 6)
	{
		if (data->tab[i] == 1)
			i++;
		else
		{
			printf("error7\n");
			return (0);
		}
	}
	return (1);
}
