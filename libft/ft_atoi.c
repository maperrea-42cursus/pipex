/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:31:40 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 18:03:26 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					neg;
	int					i;

	result = 0;
	i = 0;
	neg = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		neg = (str[i++] == '-');
	while (str[i] >= 48 && str[i] <= 57)
		result = (result * 10) + (str[i++] - 48);
	return (((neg == 1) * -result) + ((neg != 1) * result));
}
