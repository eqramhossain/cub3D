/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:50:46 by egerin            #+#    #+#             */
/*   Updated: 2025/11/10 14:50:59 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_textures *textures)
{
	textures->EA = NULL;
	textures->NO = NULL;
	textures->SO = NULL;
	textures->WE = NULL;
}

void	free_textures(t_textures *textures)
{
	free(textures->EA);
	free(textures->NO);
	free(textures->SO);
	free(textures->WE);
}

void free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
