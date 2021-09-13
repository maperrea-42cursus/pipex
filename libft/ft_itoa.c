/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:34:12 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 00:37:56 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned long long n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(long long n)
{
	unsigned long long	dup;
	int					size;
	char				*nbr;
	int					neg;

	neg = (n < 0);
	size = (n <= 0);
	dup = ((n < 0) * -n) + ((n >= 0) * n);
	size += get_size(dup);
	nbr = ft_calloc(1, sizeof(char) * (size + 1));
	if (!nbr)
		return (NULL);
	size--;
	while (size >= 0)
	{
		nbr[size] = (dup % 10) + 48;
		size--;
		dup = dup / 10;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
