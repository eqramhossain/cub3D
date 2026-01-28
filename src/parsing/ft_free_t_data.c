/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:02:48 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/28 12:31:39 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_file_content(char **file_content)
{
	int	i;

	i = 0;
	while (file_content[i])
	{
		free(file_content[i]);
		i++;
	}
	free(file_content);
}

void	ft_free_t_data(t_data *data)
{
	if (data->file_content)
		ft_free_file_content(data->file_content);
	free(data->texture);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
