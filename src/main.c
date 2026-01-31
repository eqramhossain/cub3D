/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:51:31 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/31 22:21:07 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_print_file_content(char **file_content)
{
	int	i;

	i = 0;
	while (file_content[i])
	{
		printf("%s\n", file_content[i]);
		i++;
	}
}

static int	ft_init_t_file(t_data *data)
{
	char	*raw_file_content;

	if (ft_check_file_extention(data->file_name) == ERROR)
		return (ft_error("incorrect file extention"), ERROR);
	if ((raw_file_content = ft_read(data)) == NULL)
		return (ERROR);
	data->file_content = ft_split(raw_file_content, '\n');
	free(raw_file_content);
	if (!data->file_content[0])
		return (ft_error("provided file is empty"), ERROR);
	return (SUCCESS);
}

void	ft_init_struct(t_data *data)
{
	data->texture = ft_calloc(1, sizeof(t_texture));
	data->img = ft_calloc(1, sizeof(t_img));
	data->player = ft_calloc(1, sizeof(t_player));
	data->ray = ft_calloc(1, sizeof(t_ray));
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_error("usage ./cub3d [map name]"), 1);
	data.file_name = av[1];
	ft_init_struct(&data);
	if (ft_init_t_file(&data) == ERROR)
		return (ERROR);
	if (ft_parsing(&data) == ERROR)
		return (ft_free_t_data(&data), ERROR);
	ft_print_file_content(data.file_content); // this will be removed
	mlx_loop(data.mlx_ptr);
	ft_free_t_data(&data);
	return (SUCCESS);
}
