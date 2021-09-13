/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:42:37 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 00:26:38 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *)src)[i])
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (&(((unsigned char *)dst)[i + 1]));
		i++;
	}
	return (NULL);
}
