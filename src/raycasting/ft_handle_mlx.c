/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:09:19 by ehossain          #+#    #+#             */
/*   Updated: 2025/11/21 18:27:10 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_handle_mlx(t_data *data)
{
	ft_init_mlx(data);
	ft_generate_sprites(data, data->textures);
}

void	ft_init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
}
