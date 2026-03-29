/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:51:33 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/29 14:51:55 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_copy_map(t_data *data)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (data->map[len])
		len++;
	data->map_copy = ft_calloc(len + 1, sizeof(char *));
	if (!data->map_copy)
		return (ERROR);
	while (data->map[i])
	{
		data->map_copy[i] = ft_strdup(data->map[i]);
		if (!data->map_copy[i])
			return (ERROR);
		i++;
	}
	data->map_copy[i] = NULL;
	return (SUCCESS);
}
