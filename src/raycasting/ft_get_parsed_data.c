/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parsed_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:09:51 by ehossain          #+#    #+#             */
/*   Updated: 2025/11/21 21:41:24 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_parsed_data(t_data *data, t_player *player, t_textures *textures)
{
	ft_handle_mlx(data);
	ft_print_t_data(data);
	ft_print_t_player(player);
	ft_print_t_textures(textures);
}
