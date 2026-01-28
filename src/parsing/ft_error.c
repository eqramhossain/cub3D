/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:28:44 by ehossain          #+#    #+#             */
/*   Updated: 2026/01/28 12:38:45 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str)
{
	if (!str)
		return ;
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
}
