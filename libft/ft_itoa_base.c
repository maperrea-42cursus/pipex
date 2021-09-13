/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:00:17 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 00:37:06 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned long long n, int base_size)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n = n / base_size;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(long long n, const char *base)
{
	unsigned long long	dup;
	int					size;
	char				*nbr;
	int					neg;
	int					base_size;

	neg = (n < 0);
	size = (n <= 0);
	dup = ((n < 0) * -n) + ((n >= 0) * n);
	base_size = ft_strlen(base);
	size += get_size(dup, base_size);
	nbr = ft_calloc(1, sizeof(char) * (size + 1));
	if (!nbr)
		return (NULL);
	size--;
	while (size >= neg)
	{
		nbr[size] = base[dup % base_size];
		size--;
		dup = dup / base_size;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
