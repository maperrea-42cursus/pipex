/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:34:12 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/12 23:38:09 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned long long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_utoa(unsigned long long n)
{
	int					size;
	char				*nbr;

	size = 0;
	size += get_size(n);
	nbr = ft_calloc(1, sizeof(char) * (size + 1));
	if (!nbr)
		return (NULL);
	size--;
	while (size >= 0)
	{
		nbr[size] = (n % 10) + 48;
		size--;
		n = n / 10;
	}
	return (nbr);
}
