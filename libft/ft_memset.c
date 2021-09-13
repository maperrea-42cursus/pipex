/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:25:44 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 00:25:48 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	ptr = (unsigned char *)b;
	ch = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr[i] = ch;
		i++;
	}
	return (b);
}
