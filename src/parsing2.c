/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:57:57 by egerin            #+#    #+#             */
/*   Updated: 2025/11/16 19:49:27 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures(t_data *data, char *flag, int j)
{
	char	*trim;
	int		i;
	int		k;

	if (!data || !data->map)
		return (0);
	k = 0;
	i = 0;
	while (data->map[i])
	{
		trim = ft_strtrim(data->map[i], " \t\n");
		if (!trim)
		{
			i++;
			continue ;
		}
		if (j == 2 && ft_strncmp(trim, flag, j) == 0 && ft_strstr(trim,
				".xpm") != NULL)
			k++;
		else if (j == 1 && ft_strncmp(trim, flag, j) == 0)
			k++;
		free(trim);
		if (k > 1)
			return (0);
		i++;
	}
	if (k == 0)
		return (0);
	return (1);
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
		if (ft_strstr(trim, "NO") != NULL)
		{
			textures->NO = ft_strdup(ft_strstr(trim, "textures"));
			j++;
		}
		else if (ft_strstr(trim, "SO") != NULL)
		{
			textures->SO = ft_strdup(ft_strstr(trim, "textures"));
			j++;
		}
		else if (ft_strstr(trim, "WE") != NULL)
		{
			textures->WE = ft_strdup(ft_strstr(trim, "textures"));
			j++;
		}
		else if (ft_strstr(trim, "EA") != NULL)
		{
			textures->EA = ft_strdup(ft_strstr(trim, "textures"));
			j++;
		}
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
	char	*tmp;
	char	**tab;

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
		if (ft_strstr(trim, "F ") != NULL)
		{
			tmp = trim + 2;
			tab = ft_split(tmp, ',');
			copy_textures(textures, tab, 0);
			j++;
		}
		else if (ft_strstr(trim, "C ") != NULL)
		{
			tmp = trim + 2;
			tab = ft_split(tmp, ',');
			copy_textures(textures, tab, 1);
			j++;
		}
		free(trim);
		i++;
	}
	if (j == 2)
		return (1);
	return (0);
}

int	find_map_start(t_data *data)
{
	int		i;
	char	*trim;

	// int	j;
	i = 0;
	// j = 0;
	while (data->map[i])
	{
		trim = ft_strtrim(data->map[i], " \t\n");
		if (ft_strncmp(trim, "NO ", 3) == 0 || ft_strncmp(trim, "SO ", 3) == 0
			|| ft_strncmp(trim, "WE ", 3) == 0 || ft_strncmp(trim, "EA ",
				3) == 0 || ft_strncmp(trim, "F ", 2) == 0 || ft_strncmp(trim,
				"C ", 2) == 0)
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

int	check_walls(t_data *data)
{
	char	*trim;
	int		i;
	int		j;

	data->map_start = find_map_start(data);
	data->map_end = data->map_start;
	while (data->map[data->map_end])
	{
		if (!is_map_line2(data->map[data->map_end], data))
			return (0);
		data->map_end++;
	}
	data->map_end--;
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
		if (i == data->map_start || i == data->map_end)
		{
			j = 0;
			while (trim[j])
			{
				if (trim[j] != '1' && trim[j] != ' ')
					return (free(trim), 0);
				j++;
			}
		}
		else
		{
			if ((trim[0] != '1' && trim[0] != ' ') || (trim[ft_strlen(trim)
					- 1] != '1' && trim[ft_strlen(trim) - 1] != ' '))
				return (free(trim), 0);
		}
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

int	check_map_file(t_data *data, t_textures *textures)
{
	if (!check_textures(data, "NO", 2) || !check_textures(data, "SO", 2)
		|| !check_textures(data, "WE", 2) || !check_textures(data, "EA", 2)
		|| !check_textures(data, "F", 1) || !check_textures(data, "C", 1)
		|| !store_textures(data, textures) || !store_rgb(data, textures)
		|| !check_rgb(textures) || !check_walls(data))
		return (0);
	printf("%s\n", textures->NO);
	printf("%s\n", textures->SO);
	printf("%s\n", textures->WE);
	printf("%s\n", textures->EA);
	printf("%d\n", textures->floor_tab[0]);
	printf("%d\n", textures->floor_tab[1]);
	printf("%d\n", textures->floor_tab[2]);
	printf("%d\n", textures->ceiling_tab[0]);
	printf("%d\n", textures->ceiling_tab[1]);
	printf("%d\n", textures->ceiling_tab[2]);
	printf("ci bon\n");
	return (1);
}

/*
rgb entre 0 et 255
*/
