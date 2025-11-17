/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:37:13 by ehossain          #+#    #+#             */
/*   Updated: 2025/11/17 20:37:32 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_textures(t_textures *textures, char **tab, int i)
{
	if (i == 0)
	{
		textures->floor_tab[0] = ft_atoi(tab[0]);
		textures->floor_tab[1] = ft_atoi(tab[1]);
		textures->floor_tab[2] = ft_atoi(tab[2]);
		free_tab(tab);
	}
	if (i == 1)
	{
		textures->ceiling_tab[0] = ft_atoi(tab[0]);
		textures->ceiling_tab[1] = ft_atoi(tab[1]);
		textures->ceiling_tab[2] = ft_atoi(tab[2]);
		free_tab(tab);
	}
}
