/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:44:52 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 01:11:45 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi_base(const char *str, const char *base)
{
	unsigned long long	result;
	int					neg;
	int					i;
	int					value;
	int					base_size;

	result = 0;
	i = 0;
	neg = 0;
	base_size = ft_strlen(base);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		neg = (str[i++] == '-');
	value = ft_strchr(base, str[i]);
	while (value != -1)
	{
		result = (result * base_size) + value;
		i++;
		value = ft_strchr(base, str[i]);
	}
	return (((neg == 1) * -result) + ((neg != 1) * result));
}
