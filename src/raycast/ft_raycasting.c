/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 23:07:57 by ehossain          #+#    #+#             */
/*   Updated: 2026/03/25 23:44:37 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map_height_width(t_data *data)
{
	int	i;
	int	j;
	int	size;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	size = 0;
	while (data->map[i])
	{
		if (j == 0 || len < (int)ft_strlen(data->map[j]))
			len = ft_strlen(data->map[j]);
		i++;
		j++;
	}
	size = i;
	data->map_width = len;
	data->map_height = size;
	return (SUCCESS);
}

int	ft_create_image_buffer(t_data *data)
{
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, data->win_width,
			data->win_height);
	if (!data->img->img_ptr)
		return (ERROR);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	if (!data->img->addr)
		return (ERROR);
	return (SUCCESS);
}

void	ft_frames_per_sec(t_data *data)
{
	ft_raycaster_engine(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0,
		0);
}

int	ft_rendering_frames(void *data)
{
	t_data	*tmp;
	int		moved;

	tmp = (t_data *)data;
	moved = ft_move_player_pos(tmp);
	if (moved == 0)
		return (0);
	else
		ft_frames_per_sec(data);
	return (0);
}

int	ft_raycasting(t_data *data)
{
	if (ft_map_height_width(data) == ERROR)
		return (ft_error("while extracting map_width & map_height"), ERROR);
	if (ft_create_image_buffer(data) == ERROR)
		return (ft_error("while creating image buffer"), ERROR);
	ft_frames_per_sec(data);
	return (SUCCESS);
}
