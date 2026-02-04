/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:54:49 by ehossain          #+#    #+#             */
/*   Updated: 2026/02/04 12:40:32 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_texture_file_access(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("ERROR\ntexture file cannot be opened: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (ERROR);
	}
	close(fd);
	return (SUCCESS);
}

char	*ft_extract_texture_path(char *line, char *identifier)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + ft_strlen(identifier);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = i;
	while (line[j] && line[j] != ' ' && line[j] != '\t' && line[j] != '\n')
		j++;
	path = ft_substr(line, i, j - i);
	if (!path)
	{
		ft_putstr_fd("ERROR:\n failed to extract ", 2);
		ft_putstr_fd(identifier, 2);
		ft_putstr_fd(" path\n", 2);
		return (NULL);
	}
	return (path);
}

char	*ft_find_texture_line(char **file_content, char *identifier)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(identifier);
	i = 0;
	while (file_content[i])
	{
		j = 0;
		while (file_content[i][j] == ' ' || file_content[i][j] == '\t')
			j++;
		if (ft_strncmp(&file_content[i][j], identifier, len) == 0)
		{
			if (file_content[i][j + len] == ' ' || file_content[i][j
				+ len] == '\t')
			{
				return (file_content[i]);
			}
		}
		i++;
	}
	return (NULL);
}

// there might me some error edge cases regarding to if line is NULL or path is NULL
int	ft_check_all_texture_file(t_data *data)
{
	char	*path;
	char	*line;

	line = ft_find_texture_line(data->file_content, "NO");
	path = ft_extract_texture_path(line, "NO");
	if (ft_check_texture_file_access(path) == ERROR)
		return (free(path), ERROR);
	free(path);
	line = ft_find_texture_line(data->file_content, "SO");
	path = ft_extract_texture_path(line, "SO");
	if (ft_check_texture_file_access(path) == ERROR)
		return (free(path), ERROR);
	free(path);
	line = ft_find_texture_line(data->file_content, "EA");
	path = ft_extract_texture_path(line, "EA");
	if (ft_check_texture_file_access(path) == ERROR)
		return (free(path), ERROR);
	free(path);
	line = ft_find_texture_line(data->file_content, "WE");
	path = ft_extract_texture_path(line, "WE");
	if (ft_check_texture_file_access(path) == ERROR)
		return (free(path), ERROR);
	free(path);
	return (SUCCESS);
}
