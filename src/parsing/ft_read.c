/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:01:08 by ehossain          #+#    #+#             */
/*   Updated: 2026/02/11 10:09:04 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_read_file_content(char *read_file, char *line, int fd)
{
	char	*tmp;

	while (line)
	{
		tmp = ft_strjoin(read_file, line);
		free(read_file);
		read_file = tmp;
		free(line);
		line = get_next_line(fd);
	}
	return (read_file);
}

char	*ft_read(t_data *data)
{
	int		fd;
	char	*read_file_content;
	char	*line;

	fd = open(data->file_name, O_RDONLY);
	if (fd == -1)
		return (ft_error("while opening file"), NULL);
	line = get_next_line(fd);
	if (!line)
	{
		ft_error("provided file is empty, please verify");
		close(fd);
		return (NULL);
	}
	read_file_content = ft_strdup("");
	read_file_content = ft_read_file_content(read_file_content, line, fd);
	close(fd);
	return (read_file_content);
}
