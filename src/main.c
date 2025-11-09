/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:44:15 by egerin            #+#    #+#             */
/*   Updated: 2025/11/09 20:00:13 by egerin           ###   ########.fr       */
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

void	parsing(t_map *data, t_textures *textures)
{
	if (!check_map_file(data, textures))
	{
		free_tab(data->map);
		exit(1);
	}
}

// int main(int ac, char **av)
// {
// 	(void)ac;
//     char *tmp = read_map(av[1]);
//     printf("Content: %s\n", tmp);
//     free(tmp);
//     return (0);
// }

int	main(int ac, char **av)
{
	t_map	data;
	t_textures	textures;
	char	*tmp;

	init_textures(&textures);
	ft_memset(&data, 0, sizeof(t_map));
	if (ac != 2)
	{
		write (2, "usage : ./cub3d [map name]\n", 27);
		return(0);
	}
	if (!check_file_extension(av[1], ".cub"))
		return (write(2, "only .cub files\n", 16), 0);
	tmp = read_map(av[1]);
	data.map = ft_split(tmp, '\n');
	free(tmp);
	parsing(&data, &textures);
	if (data.map)
		free_tab(data.map);
	return (0);
}
