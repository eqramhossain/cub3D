/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_new_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:36:40 by ehossain          #+#    #+#             */
/*   Updated: 2026/04/27 19:16:53 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_flag_cmd(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 'C')
		return (SUCCESS);
	else if (str[i] == 'F')
		return (SUCCESS);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		return (SUCCESS);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		return (SUCCESS);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		return (SUCCESS);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		return (SUCCESS);
	return (ERROR);
}

static t_var	ft_get_start_end(char *raw_file_content, int i)
{
	t_var	var;

	var.end = i - 1;
	while (i != 0)
	{
		if (ft_flag_cmd(&raw_file_content[i]) == SUCCESS)
			break ;
		i--;
	}
	while (raw_file_content[i] != '\n')
		i++;
	var.start = i;
	while (raw_file_content[var.start] == '\n')
		var.start++;
	while (raw_file_content[var.end] == '\n')
		var.end--;
	return (var);
}

int	ft_map_new_line(char *raw_file_content)
{
	int		i;
	t_var	var;
	int		counter;

	i = 0;
	counter = 0;
	while (raw_file_content[i])
	{
		if (ft_flag_cmd(&raw_file_content[i]) == SUCCESS)
			counter++;
		i++;
	}
	if (counter != 6)
		return (SUCCESS);
	var = ft_get_start_end(raw_file_content, i);
	while (var.start < var.end)
	{
		if (raw_file_content[var.start] == '\n' && raw_file_content[var.start
			+ 1] == '\n')
			return (ft_error("new line found in map area"), ERROR);
		var.start++;
	}
	return (SUCCESS);
}
