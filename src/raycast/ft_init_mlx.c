/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:07:35 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/31 21:08:45 by ehossain         ###   ########.fr       */
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
	(void)data;
	if (keycode == ESC)
		ft_destroy_all(data);
	if (keycode == W)
		printf("W pressed\n");
	if (keycode == A)
		printf("A pressed\n");
	if (keycode == S)
		printf("S pressed\n");
	if (keycode == D)
		printf("D pressed\n");
	if (keycode == LEFT)
		printf("LEFT pressed\n");
	if (keycode == RIGHT)
		printf("RIGHT pressed\n");
	return (0);
}

int	ft_release_handler(int keycode, void *data)
{
	(void)data;
	if (keycode == ESC)
		ft_destroy_all(data);
	if (keycode == W)
		printf("W released\n");
	if (keycode == A)
		printf("A released\n");
	if (keycode == S)
		printf("S released\n");
	if (keycode == D)
		printf("D released\n");
	if (keycode == LEFT)
		printf("LEFT released\n");
	if (keycode == RIGHT)
		printf("RIGHT released\n");
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
