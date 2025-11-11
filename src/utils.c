/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:50:46 by egerin            #+#    #+#             */
/*   Updated: 2025/11/11 17:01:42 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_textures *textures)
{
	textures->EA = NULL;
	textures->NO = NULL;
	textures->SO = NULL;
	textures->WE = NULL;
}

void	free_textures(t_textures *textures)
{
	free(textures->EA);
	free(textures->NO);
	free(textures->SO);
	free(textures->WE);
}

void free_tab(char **tab)
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

int	is_map_line(char *line)
{
    int	i;

    if (!line || ft_strlen(line) == 0)
        return (0);
    i = 0;
    while (line[i])
    {
        if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S' \
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ' \
			&& line[i] != '\t' && line[i] != '\n')
            return (0);
        i++;
    }
    return (1);
}

void	copy_textures(t_textures *textures, char **tab, int i)
{
	if (i == 0)
	{
		textures->floor_tab[0] = ft_atoi(tab[0]);
		textures->floor_tab[1] = ft_atoi(tab[1]);
		textures->floor_tab[2] = ft_atoi(tab[2]);
		free_tab(tab);
	}
	if (i == 1)
	{
		textures->ceiling_tab[0] = ft_atoi(tab[0]);
		textures->ceiling_tab[1] = ft_atoi(tab[1]);
		textures->ceiling_tab[2] = ft_atoi(tab[2]);
		free_tab(tab);
	}
}
