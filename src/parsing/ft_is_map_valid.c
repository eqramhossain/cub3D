/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:58:19 by ehossain          #+#    #+#             */
/*   Updated: 2026/02/08 12:15:17 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_copy_map(t_data *data)
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

static int	ft_get_max_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	ft_is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	ft_free_map_copy(t_data *data)
{
	int	i;

	if (!data->map_copy)
		return ;
	i = 0;
	while (data->map_copy[i])
	{
		free(data->map_copy[i]);
		i++;
	}
	free(data->map_copy);
	data->map_copy = NULL;
}

static int	ft_flood_fill(char **map, int x, int y, int max_y)
{
	if (y < 0 || y >= max_y)
		return (ERROR);
	if (x < 0 || x >= (int)ft_strlen(map[y]))
		return (ERROR);
	if (map[y][x] == ' ')
		return (ERROR);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (SUCCESS);
	if (ft_is_walkable(map[y][x]))
		map[y][x] = 'V';
	if (ft_flood_fill(map, x, y - 1, max_y) == ERROR)
		return (ERROR);
	if (ft_flood_fill(map, x, y + 1, max_y) == ERROR)
		return (ERROR);
	if (ft_flood_fill(map, x - 1, y, max_y) == ERROR)
		return (ERROR);
	if (ft_flood_fill(map, x + 1, y, max_y) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	ft_is_map_valid(t_data *data)
{
	int	max_y;

	if (ft_copy_map(data) == ERROR)
		return (ERROR);
	max_y = ft_get_max_y(data->map_copy);
	if (ft_flood_fill(data->map_copy, (int)data->player->pos_x,
			(int)data->player->pos_y, max_y) == ERROR)
	{
		ft_free_map_copy(data);
		return (ft_error("flood fill. map is not valid"), ERROR);
	}
	printf("map is valid\n"); // this one have to remove
	ft_free_map_copy(data);
	return (SUCCESS);
	return (SUCCESS);
}
