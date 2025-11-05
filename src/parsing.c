/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:16:41 by egerin            #+#    #+#             */
/*   Updated: 2025/11/05 15:42:19 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_new_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			ft_printf("Error\nNewline in the map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_file_extension(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0 && str[i] != '.')
		i--;
	if (ft_strncmp(&str[i], ".cub", 5) == 0)
		return (1);
	return (0);
}

static char	*read_map_content(int fd, char *map, char *line)
{
	char	*tmp;

	while (line)
	{
		tmp = ft_strjoin(map, line);
		free(map);
		map = tmp;
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

void	check_file(char *str, int fd)
{
	if (!str)
	{
		close(fd);
		ft_printf("Error file content\n");
		exit(0);
	}
}

char	*read_map(char *file)
{
	int		fd;
	char	*line;
	char	*map;

	line = "";
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write (1, "problem with map file\n", 22);
		exit (1);
	}
	line = get_next_line(fd);
	if (!line)
		check_file(line, fd);
	map = ft_strdup("");
	if (line)
		map = read_map_content(fd, map, line);
	close(fd);
	if (!check_new_line(map))
	{
		free(map);
		write (2, "consecutive newlines\n", 21);
		exit(1);
	}
	return (map);
}
