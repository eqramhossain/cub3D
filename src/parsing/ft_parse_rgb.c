/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:57:47 by ehossain          #+#    #+#             */
/*   Updated: 2026/04/07 15:28:10 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_trim_whitespace(char *str)
{
	int		i;
	int		start;
	int		end;
	char	*trimmed;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	start = i;
	end = ft_strlen(str) - 1;
	while (end > start && (str[end] == ' ' || str[end] == '\t'
			|| str[end] == '\n'))
		end--;
	trimmed = ft_substr(str, start, end - start + 1);
	return (trimmed);
}

static void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	ft_count_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

static int	ft_is_num(char *trimmed)
{
	int	i;

	i = 0;
	while (trimmed[i])
	{
		if (trimmed[i] < '0' || trimmed[i] > '9')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	ft_parse_rgb(char *color_str, int *rgb_array)
{
	char	**split;
	char	*trimmed;
	int		i;

	split = ft_split(color_str, ',');
	if (!split || ft_count_split(split) != 3)
	{
		if (split)
			ft_free_split(split);
		return (ft_error("RGB format must be R,G,B"), free(color_str), ERROR);
	}
	i = 0;
	while (i < 3)
	{
		trimmed = ft_trim_whitespace(split[i]);
		if (ft_is_num(trimmed) == ERROR)
			return (ft_free_split(split), free(trimmed), free(color_str),
				ft_error("RGB format must be R,G,B"), ERROR);
		rgb_array[i] = ft_atoi(trimmed);
		free(trimmed);
		i++;
	}
	ft_free_split(split);
	return (SUCCESS);
}
