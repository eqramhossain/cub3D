/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:37:05 by ehossain          #+#    #+#             */
/*   Updated: 2026/02/04 16:10:27 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_file(t_data *data)
{
	if (ft_check_all_texture_flag(data) == ERROR)
		return (ERROR);
	if (ft_check_all_texture_file(data) == ERROR)
		return (ERROR);
	if (ft_store_all_texture_file(data) == ERROR)
		return (ERROR);
	if (ft_check_floor_ceiling_flag(data) == ERROR)
		return (ERROR);
	if (ft_store_floor_ceiling_color(data) == ERROR)
		return (ERROR);
	if (ft_is_rgb_valid(data->texture) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	ft_check_map(t_data *data)
{
	if (ft_is_map_last(data) == ERROR)
		return (ft_error("map is not the last element"), ERROR);
	if (ft_extract_map(data) == ERROR)
		return (ft_error("while extracting map from file"), ERROR);
	if (ft_map_char_valid(data) == ERROR)
		return (ft_error("unknown char found in map"), ERROR);
	if (ft_map_closed(data) == ERROR)
		return (ft_error("map must be closed/surrounded by walls"), ERROR);
	// if (ft_map_valid(data) == ERROR)
	// 	return (ft_error("map is not valid"), ERROR);
	return (SUCCESS);
}

int	ft_parsing(t_data *data)
{
	if (ft_init_mlx(data) == ERROR)
		return (ft_error("while initialising mlx server"), ERROR);
	if (ft_check_file(data) == ERROR)
		return (ERROR);
	if (ft_check_map(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
