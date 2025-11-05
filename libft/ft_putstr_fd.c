/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:21:58 by egerin            #+#    #+#             */
/*   Updated: 2025/09/13 17:38:02 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	ssize_t	len;

	if (!s)
	{
		if (write(fd, "(null)", 6) == 6)
			return (6);
		return (-1);
	}
	len = ft_strlen(s);
	if (len > 0)
		return ((int)write(fd, s, (size_t)len));
	return (0);
}
