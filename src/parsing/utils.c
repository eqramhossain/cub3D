/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:50:46 by egerin            #+#    #+#             */
/*   Updated: 2025/11/19 13:16:14 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_textures *textures)
{
	textures->ea = NULL;
	textures->no = NULL;
	textures->so = NULL;
	textures->we = NULL;
}

void	free_textures(t_textures *textures)
{
	free(textures->ea);
	free(textures->no);
	free(textures->so);
	free(textures->we);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	is_map_line2(char *line, t_data *data)
{
	int	i;

	if (!line || ft_strlen(line) == 0)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' '
			&& line[i] != '\t' && line[i] != '\n')
			return (0);
		else if (line[i] == 'N' || line[i] == 'W' || line[i] == 'E'
			|| line[i] == 'S')
		{
			data->tmp++;
			if (data->tmp > 1)
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_map_line(char *line)
{
	int	i;

	if (!line || ft_strlen(line) == 0)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' '
			&& line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
