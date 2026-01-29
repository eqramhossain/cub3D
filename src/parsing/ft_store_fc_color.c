/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_fc_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:48:36 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/29 14:10:36 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_trim_whitespace(char *str)
{
	int		i;
	int		start;
	int		end;
	char	*trimmed;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	start = i;
	end = ft_strlen(str) - 1;
	while (end > start && (str[end] == ' ' || str[end] == '\t'
			|| str[end] == '\n'))
		end--;
	trimmed = ft_substr(str, start, end - start + 1);
	return (trimmed);
}

static void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	ft_count_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

static int	ft_parse_rgb(char *color_str, int *rgb_array)
{
	char	**split;
	char	*trimmed;
	int		i;

	split = ft_split(color_str, ',');
	if (!split || ft_count_split(split) != 3)
	{
		if (split)
			ft_free_split(split);
		return (ft_error("RGB format must be R,G,B"), ERROR);
	}
	i = 0;
	while (i < 3)
	{
		trimmed = ft_trim_whitespace(split[i]);
		rgb_array[i] = ft_atoi(trimmed);
		free(trimmed);
		i++;
	}
	ft_free_split(split);
	return (SUCCESS);
}

static char	*ft_extract_rgb_values(char *line, char *identifier)
{
	int		i;
	int		j;
	char	*rgb_str;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + ft_strlen(identifier);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = i;
	while (line[j] && line[j] != '\n')
		j++;
	while (j > i && (line[j - 1] == ' ' || line[j - 1] == '\t'))
		j--;
	rgb_str = ft_substr(line, i, j - i);
	if (!rgb_str)
	{
		ft_putstr_fd("ERROR:\n failed to extract ", 2);
		ft_putstr_fd(identifier, 2);
		ft_putstr_fd(" RGB values\n", 2);
		return (NULL);
	}
	return (rgb_str);
}

int	ft_store_floor_ceiling_color(t_data *data)
{
	char	*line;
	char	*color_str;

	line = ft_find_texture_line(data->file_content, "F");
	if (!line)
		return (ft_error("floor color line not found"), ERROR);
	color_str = ft_extract_rgb_values(line, "F");
	if (!color_str)
		return (ERROR);
	if (ft_parse_rgb(color_str, data->texture->floor_tab) == ERROR)
		return (ERROR);
	free(color_str);
	line = ft_find_texture_line(data->file_content, "C");
	if (!line)
		return (ft_error("ceiling color line not found"), ERROR);
	color_str = ft_extract_rgb_values(line, "C");
	if (!color_str)
		return (ERROR);
	if (ft_parse_rgb(color_str, data->texture->ceiling_tab) == ERROR)
		return (ERROR);
	free(color_str);
	return (SUCCESS);
}
