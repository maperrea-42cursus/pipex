/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:37:04 by maperrea          #+#    #+#             */
/*   Updated: 2020/10/02 15:49:06 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_memswap(void *p1, void *p2, size_t bytes)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < bytes)
	{
		tmp = ((char *)p1)[i];
		((char *)p1)[i] = ((char *)p2)[i];
		((char *)p2)[i] = tmp;
		i++;
	}
}
