/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_fc_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:48:36 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/29 14:59:26 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
