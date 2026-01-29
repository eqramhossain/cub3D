/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:37:05 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/29 10:47:54 by ehossain         ###   ########.fr       */
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
	// if (ft_is_rgb_valid(data) == ERROR)
	// 	return (ERROR);
	return (SUCCESS);
}

static void	ft_init_t_texture(t_data *data)
{
	data->texture = calloc(1, sizeof(t_texture));
}

int	ft_parsing(t_data *data)
{
	if (ft_init_mlx(data) == ERROR)
		return (ft_error("while initialising mlx server"), ERROR);
	ft_init_t_texture(data);
	if (ft_check_file(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
