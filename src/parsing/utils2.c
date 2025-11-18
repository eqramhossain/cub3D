/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:37:13 by ehossain          #+#    #+#             */
/*   Updated: 2025/11/18 18:08:54 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	line_matches_flag(char *trim, char *flag, int j)
{
    if (j == 2)
        return (ft_strncmp(trim, flag, j) == 0 && ft_strstr(trim, ".xpm") != NULL);
    return (ft_strncmp(trim, flag, j) == 0);
}

int	count_unique_flag(t_data *data, char *flag, int j)
{
    int		i;
    int		k;
    char	*trim;

    i = 0;
    k = 0;
    while (data->map[i])
    {
        trim = ft_strtrim(data->map[i], " \t\n");
        if (!trim)
        {
            i++;
            continue ;
        }
        if (line_matches_flag(trim, flag, j))
            k++;
        free(trim);
        if (k > 1)
            return (0);
        i++;
    }
    return (k == 1);
}

void	store_textures_loop(char *trim, t_textures *textures, int *j)
{
	if (ft_strstr(trim, "NO") != NULL)
	{
		textures->NO = ft_strdup(ft_strstr(trim, "textures"));
		(*j)++;
	}
	else if (ft_strstr(trim, "SO") != NULL)
	{
		textures->SO = ft_strdup(ft_strstr(trim, "textures"));
		(*j)++;
	}
	else if (ft_strstr(trim, "WE") != NULL)
	{
		textures->WE = ft_strdup(ft_strstr(trim, "textures"));
		(*j)++;
	}
	else if (ft_strstr(trim, "EA") != NULL)
	{
		textures->EA = ft_strdup(ft_strstr(trim, "textures"));
		(*j)++;
	}
}

void	store_rgb_condition(t_textures *textures, char *trim, int *j)
{
	char	*tmp;
	char	**tab;

	if (ft_strstr(trim, "F ") != NULL)
	{
		tmp = trim + 2;
		tab = ft_split(tmp, ',');
		copy_textures(textures, tab, 0);
		(*j)++;
	}
	else if (ft_strstr(trim, "C ") != NULL)
	{
		tmp = trim + 2;
		tab = ft_split(tmp, ',');
		copy_textures(textures, tab, 1);
		(*j)++;
	}
}
