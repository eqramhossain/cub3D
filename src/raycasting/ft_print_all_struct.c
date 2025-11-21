/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:41:43 by ehossain          #+#    #+#             */
/*   Updated: 2025/11/21 21:41:58 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_t_data(t_data *data)
{
	printf("data->tmp = %d\n", data->tmp);
	printf("data->width = %d\n", data->width);
	printf("data->height = %d\n", data->height);
	printf("data->map = %d\n", data->map_start);
	printf("data->map_end = %d\n", data->map_end);
	printf("data->player_col = %d\n", data->player_col);
	printf("data->player_row = %d\n", data->player_row);
	if (data->mlx_ptr)
		printf("data->mlx_ptr valid\n");
	if (data->win_ptr)
		printf("data->win_ptr valid\n");
}

void	ft_print_t_player(t_player *player)
{
	printf("player->x = %lf\n", player->x);
	printf("player->y = %lf\n", player->y);
	printf("player->dir_x = %lf\n", player->dir_x);
	printf("player->dir_y = %lf\n", player->dir_y);
	printf("player->plane_x = %lf\n", player->plane_x);
	printf("player->dir_y = %lf\n", player->plane_y);
	printf("player->angle = %d\n", player->angle);
}

void	ft_print_t_textures(t_textures *textures)
{
	printf("textures->no = %s\n", textures->no);
	printf("textures->so = %s\n", textures->so);
	printf("textures->we = %s\n", textures->we);
	printf("textures->ea = %s\n", textures->ea);
	printf("textures->no_sprite = %s\n", NO_SPRITE);
	printf("textures->so_sprite = %s\n", SO_SPRITE);
	printf("textures->we_sprite = %s\n", WE_SPRITE);
	printf("textures->ea_sprite	= %s\n", EA_SPRITE);
	for (int i = 0; i < 3; i++)
	{
		printf("textures->floor_tab[%d] = %d\n", i, textures->floor_tab[i]);
	}
	printf("textures->floor = %d\n", textures->floor);
	printf("textures->ceiling = %d\n", textures->ceiling);
	for (int i = 0; i < 3; i++)
	{
		printf("textures->ceiling_tab[%d] = %d\n", i, textures->ceiling_tab[i]);
	}
}
