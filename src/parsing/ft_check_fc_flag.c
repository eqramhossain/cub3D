/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fc_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:35:02 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/29 10:46:59 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_count_identifier(char **file_content, char *identifier)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (file_content[i])
	{
		j = 0;
		while (file_content[i][j] == ' ' || file_content[i][j] == '\t')
			j++;
		if (ft_strncmp(&file_content[i][j], identifier, 1) == 0)
		{
			if (file_content[i][j + 1] == ' ' || file_content[i][j + 1] == '\t')
				count++;
		}
		i++;
	}
	return (count);
}

int	ft_check_floor_ceiling_flag(t_data *data)
{
	int	floor_count;
	int	ceiling_count;

	floor_count = ft_count_identifier(data->file_content, "F");
	if (floor_count != 1)
		return (ft_error("floor identifier F must appear exactly once"), ERROR);
	ceiling_count = ft_count_identifier(data->file_content, "C");
	if (ceiling_count != 1)
		return (ft_error("ceiling identifier C must appear exactly once"),
			ERROR);
	return (SUCCESS);
}
