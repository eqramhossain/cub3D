/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_extention.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:36:13 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/26 12:10:58 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_file_extention(char *file_name)
{
	int	len;
	int	start;
	int	result;

	len = ft_strlen(file_name);
	start = len - 4;
	result = ft_strncmp(file_name + start, ".cub", len - 4);
	if (result != 0)
		return (1);
	return (0);
}
