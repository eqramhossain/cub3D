/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:57:57 by egerin            #+#    #+#             */
/*   Updated: 2025/11/09 20:10:16 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures(t_map *data, char *flag)
{
	char	*trim;
	int	i;
	int k;

	k = 0;
	i = 0;
	while (data->map[i])
	{
		trim = ft_strtrim(data->map[i], " \t\n");
		// printf("%s\n", trim);
		if (ft_strstr(trim, flag) != NULL && check_file_extension(trim, ".xpm"))
			k++;
		if (k > 1)
			return (0);
		i++;
	}
	if (k == 0)
		return (0);
	return (1);
}

int	store_textures(t_map *data, t_textures *textures)
{
	char *trim;
	int	i;
	int	j;

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
	}
	if (j == 4)
		return (1);
	return (0);
}

int	check_map_file(t_map *data, t_textures *textures)
{
	if (!check_textures(data, "NO") || !check_textures(data, "SO") || \
	!check_textures(data, "WE") || !check_textures(data, "EA") || \
	!check_textures(data, "F") || !check_textures(data, "C"))
		printf("e");
	if (!store_textures(data, textures))
		return (0);
	printf("%s\n", textures->NO);
	printf("%s\n", textures->SO);
	printf("%s\n", textures->WE);
	printf("%s\n", textures->EA);
	printf("ci bon\n");
	return (1);
}