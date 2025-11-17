/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:46:26 by egerin            #+#    #+#             */
/*   Updated: 2025/11/17 20:11:42 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *s1, char *s2)
{
	int	s2_len;
	int	i;
	int	j;

	if (!s2)
		return (s1);
	s2_len = ft_strlen(s2);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i + j] == s2[j])
				j++;
			else
				break ;
		}
		if (j == s2_len)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
