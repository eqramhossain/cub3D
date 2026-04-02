/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_rgb_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:40:47 by ehossain          #+#    #+#             */
/*   Updated: 2026/04/02 10:50:13 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_create_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	ft_is_rgb_valid(t_texture *texture)
{
	if ((texture->floor_tab[0] < 0 || texture->floor_tab[0] > 255)
		|| (texture->floor_tab[1] < 0 || texture->floor_tab[1] > 255)
		|| (texture->floor_tab[2] < 0 || texture->floor_tab[2] > 255))
		return (ft_error("can't create floor color, verify the inputs"), ERROR);
	texture->floor = ft_create_color(texture->floor_tab[0],
			texture->floor_tab[1], texture->floor_tab[2]);
	if ((texture->ceiling_tab[0] < 0 || texture->ceiling_tab[0] > 255)
		|| (texture->ceiling_tab[1] < 0 || texture->ceiling_tab[1] > 255)
		|| (texture->ceiling_tab[2] < 0 || texture->ceiling_tab[2] > 255))
		return (ft_error("can't create ceiling color, verify the inputs"),
			ERROR);
	texture->ceiling = ft_create_color(texture->ceiling_tab[0],
			texture->ceiling_tab[1], texture->ceiling_tab[2]);
	return (SUCCESS);
}
