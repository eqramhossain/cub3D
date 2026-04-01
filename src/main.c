/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:51:31 by ehossain          #+#    #+#             */
/*   Updated: 2026/04/01 11:39:07 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	ft_print_file_content(char **file_content)
// {
// 	int	i;
//
// 	i = 0;
// 	while (file_content[i])
// 	{
// 		printf("%s\n", file_content[i]);
// 		i++;
// 	}
// }
// static void	ft_print_data(t_data *data)
// {
// 	printf("\n");
// 	printf("\n");
// 	printf("\n");
// 	printf("data->texture->no_texture = %s\n", data->texture->no_texture);
// 	printf("data->texture->no_texture = %s\n", data->texture->so_texture);
// 	printf("data->texture->no_texture = %s\n", data->texture->ea_texture);
// 	printf("data->texture->no_texture = %s\n", data->texture->we_texture);
// 	for (int i = 0; i < 3; i++)
// 		printf("data->texture->floor_tab[i] = %d\n",
// 			data->texture->floor_tab[i]);
// 	for (int i = 0; i < 3; i++)
// 		printf("data->texture->ceiling_tab[i] = %d\n",
// 			data->texture->ceiling_tab[i]);
// 	printf("data->texture->floor = %d\n", data->texture->floor);
// 	printf("data->texture->ceiling = %d\n", data->texture->ceiling);
// 	ft_print_file_content(data->map);
// }

static int	ft_init_t_file(t_data *data)
{
	char	*raw_file_content;

	if (ft_check_file_extention(data->file_name) == ERROR)
		return (ft_error("incorrect file extention"), ERROR);
	raw_file_content = ft_read(data);
	if (raw_file_content == NULL)
		return (ERROR);
	// if all the flag found extract and hold.
	// then continue until somthing are found until a end of file or encounter a '\n'
	// then extract it too and hold
	// then join these two
	// then continue the program
	data->file_content = ft_split(raw_file_content, '\n');
	free(raw_file_content);
	if (!data->file_content[0])
		return (ft_error("provided file is empty"), ERROR);
	return (SUCCESS);
}

void	ft_init_texture(t_texture *texture)
{
	texture->no_texture = NULL;
	texture->so_texture = NULL;
	texture->ea_texture = NULL;
	texture->we_texture = NULL;
	texture->tex_helper = malloc(1 * sizeof(t_tex_helper));
	texture->tex_helper->no_wall = NULL;
	texture->tex_helper->so_wall = NULL;
	texture->tex_helper->ea_wall = NULL;
	texture->tex_helper->we_wall = NULL;
	texture->tex_helper->no_addr = NULL;
	texture->tex_helper->so_addr = NULL;
	texture->tex_helper->ea_addr = NULL;
	texture->tex_helper->we_addr = NULL;
}

void	ft_init_img(t_img *img)
{
	img->img_ptr = NULL;
	img->addr = NULL;
}

void	ft_init_struct(t_data *data)
{
	data->file_content = NULL;
	data->file_name = NULL;
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->win_width = WIN_WIDTH;
	data->win_height = WIN_HEIGHT;
	data->texture = malloc(1 * sizeof(t_texture));
	ft_init_texture(data->texture);
	data->img = malloc(1 * sizeof(t_img));
	ft_init_img(data->img);
	data->player = malloc(1 * sizeof(t_player));
	data->ray = malloc(1 * sizeof(t_ray));
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_error("usage ./cub3d [map name]"), 1);
	ft_init_struct(&data);
	data.file_name = av[1];
	if (ft_init_t_file(&data) == ERROR)
		return (ft_free_t_data(&data), ERROR);
	if (ft_parsing(&data) == ERROR)
		return (ft_free_t_data(&data), ERROR);
	if (ft_raycasting(&data) == ERROR)
		return (ft_error("raycaster engine, leaks to implemented."), ERROR);
	mlx_loop_hook(data.mlx_ptr, ft_rendering_frames, (void *)&data);
	mlx_loop(data.mlx_ptr);
	ft_free_t_data(&data);
	return (SUCCESS);
}
