/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:16:30 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 00:04:16 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, int size)
{
	int	i;
	int	j;
	int	return_val;

	if (ft_strlen(dst) > size)
		return_val = ft_strlen(src) + size;
	else
		return_val = ft_strlen(src) + ft_strlen(dst);
	i = 0;
	j = ft_strlen(dst);
	if (j > size)
		return (return_val);
	while (j < size - 1 && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	return (return_val);
}
