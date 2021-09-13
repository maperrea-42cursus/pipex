/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:21:47 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 18:06:06 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl	dbl_to_t_dbl(double n)
{
	t_dbl			dbl;
	unsigned char	*nbr;
	unsigned char	*tmp;

	nbr = (unsigned char *)&n;
	dbl.sign = nbr[7] >> 7;
	tmp = (unsigned char *)&(dbl.mantissa);
	ft_memcpy(tmp, nbr, 8);
	tmp[7] = 0;
	tmp[6] = tmp[6] & 0b00001111;
	dbl.exponent = 0;
	tmp = (unsigned char *)&(dbl.exponent);
	tmp[1] = (nbr[7] >> 4) & 0b00000111;
	tmp[0] = (nbr[7] << 4) | (nbr[6] >> 4);
	if (!dbl.exponent)
	{
		if (dbl.mantissa)
			dbl.exponent = -1022;
	}
	else if (dbl.exponent != 2047)
	{
		dbl.mantissa |= 1l << 52;
		dbl.exponent -= 1023;
	}
	return (dbl);
}

char	*pos_exp(char *nbr, int exponent)
{
	int	i;
	int	len;

	if (!exponent)
		return (nbr);
	i = 1;
	nbr[0] += nbr[0] - '0';
	if (nbr[0] > '9')
	{
		nbr[0] -= 10;
		nbr = ft_strjoin("1", nbr);
		i++;
	}
	len = ft_strlen(nbr);
	while (i < len)
	{
		nbr[i] += nbr[i] - '0';
		if (nbr[i] > '9')
		{
			nbr[i] -= 10;
			(nbr[i - 1])++;
		}
		i++;
	}
	return (pos_exp(nbr, exponent - 1));
}

char	*neg_exp(char *nbr, int exponent)
{
	int	i;
	int	dot_pos;

	if (!exponent)
		return (nbr);
	dot_pos = ft_strchr(nbr, '.');
	i = ft_strlen(nbr) - 2;
	if ((nbr[i + 1] - '0') % 2)
		nbr = ft_strjoin(nbr, &".5"[dot_pos == -1]);
	nbr[i + 1] = ((nbr[i + 1] - '0') / 2) + '0';
	while (i >= 0)
	{
		if (i == dot_pos)
			i--;
		if ((nbr[i] - '0') % 2)
			nbr[i + 1 + (i + 1 == dot_pos)] += 5;
		nbr[i] = ((nbr[i] - '0') / 2) + '0';
		i--;
	}
	if (nbr[0] == '0' && nbr[1] != '.')
		nbr = ft_strtrim(nbr, "0");
	return (neg_exp(nbr, exponent + 1));
}

char	*ftoa(double nbr)
{
	char			*str;
	t_dbl			dbl;
	int				i;

	dbl = dbl_to_t_dbl(nbr);
	if (dbl.exponent == 2047)
	{
		if (dbl.mantissa)
			str = ft_strdup("nan");
		else
			str = ft_strdup("inf");
		return (ft_strjoin(&"-"[dbl.sign && !dbl.mantissa], str));
	}
	i = 53;
	while (--i && !(dbl.mantissa & 1))
		dbl.mantissa >>= 1;
	dbl.exponent -= i;
	str = ft_utoa(dbl.mantissa);
	if (dbl.exponent > 0)
		str = pos_exp(str, dbl.exponent);
	else if (dbl.exponent < 0)
		str = neg_exp(str, dbl.exponent);
	if (dbl.exponent >= 0)
		str = ft_strjoin(str, ".");
	return (ft_strjoin(&"-"[(int)dbl.sign], str));
}
