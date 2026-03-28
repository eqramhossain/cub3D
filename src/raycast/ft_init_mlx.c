/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:07:35 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/28 23:10:56 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_destroy_all(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_free_t_data(data);
	exit(0);
	return (0);
}

int	ft_press_handler(int keycode, void *data)
{
	t_data	*tempo;

	tempo = (t_data *)data;
	if (keycode == ESC)
		ft_destroy_all(data);
	if (keycode == W)
		tempo->player->move_y = 1;
	if (keycode == A)
		tempo->player->move_x = -1;
	if (keycode == S)
		tempo->player->move_y = -1;
	if (keycode == D)
		tempo->player->move_x = 1;
	if (keycode == LEFT)
		tempo->player->rotate -= 1;
	if (keycode == RIGHT)
		tempo->player->rotate += 1;
	return (0);
}

int	ft_release_handler(int keycode, void *data)
{
	t_data	*tempo;

	tempo = (t_data *)data;
	if (keycode == ESC)
		ft_destroy_all(data);
	if (keycode == W && tempo->player->move_y == 1)
		tempo->player->move_y = 0;
	if (keycode == A && tempo->player->move_x == -1)
		tempo->player->move_x = 0;
	if (keycode == S && tempo->player->move_y == -1)
		tempo->player->move_y = 0;
	if (keycode == D && tempo->player->move_x == 1)
		tempo->player->move_x = 0;
	if (keycode == LEFT && tempo->player->rotate == -1)
		tempo->player->rotate = 0;
	if (keycode == RIGHT && tempo->player->rotate == 1)
		tempo->player->rotate = 0;
	return (0);
}

int	ft_init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"cub3D");
	if (!data->win_ptr)
		return (ERROR);
	mlx_hook(data->win_ptr, 17, (1L << 17), ft_destroy_all, (void *)data);
	mlx_hook(data->win_ptr, 2, (1L << 0), ft_press_handler, (void *)data);
	mlx_hook(data->win_ptr, 3, (1L << 1), ft_release_handler, (void *)data);
	return (SUCCESS);
}
