/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:57:57 by egerin            #+#    #+#             */
/*   Updated: 2025/11/18 18:14:35 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures(t_data *data, char *flag, int j)
{
    if (!data || !data->map)
        return (0);
    return (count_unique_flag(data, flag, j));
}

int	store_textures(t_data *data, t_textures *textures)
{
	char	*trim;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		trim = ft_strtrim(data->map[i], " \t\n");
		store_textures_loop(trim, textures, &j);
		i++;
		free(trim);
	}
	if (j == 4)
		return (1);
	return (0);
}

int	store_rgb(t_data *data, t_textures *textures)
{
	int		i;
	int		j;
	char	*trim;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		trim = ft_strtrim(data->map[i], " \t\n");
		if (!trim)
		{
			i++;
			continue ;
		}
		store_rgb_condition(textures, trim, &j);
		free(trim);
		i++;
	}
	if (j == 2)
		return (1);
	return (0);
}

int	check_walls(t_data *data)
{
	char	*trim;
	int		i;
	int		j;

	if (!find_map_end(data))
		return (0);
	i = data->map_start;
	while (i <= data->map_end)
	{
		trim = ft_strtrim(data->map[i], " \t\n");
		if (!trim || ft_strlen(trim) == 0)
		{
			if (trim)
				free(trim);
			i++;
			continue ;
		}
		if (!check_walls_helper(data, trim, &j, i))
			return (free(trim), 0);
		free(trim);
		i++;
	}
	return (1);
}

int	check_rgb(t_textures *textures)
{
	if ((textures->floor_tab[0] < 0 || textures->floor_tab[0] > 255)
		|| (textures->floor_tab[1] < 0 || textures->floor_tab[1] > 255)
		|| (textures->floor_tab[2] < 0 || textures->floor_tab[2] > 255))
		return (0);
	if ((textures->ceiling_tab[0] < 0 || textures->ceiling_tab[0] > 255)
		|| (textures->ceiling_tab[1] < 0 || textures->ceiling_tab[1] > 255)
		|| (textures->ceiling_tab[2] < 0 || textures->ceiling_tab[2] > 255))
		return (0);
	return (1);
}
