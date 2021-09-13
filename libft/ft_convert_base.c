/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:58:34 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/07 00:58:04 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base(char *str, char *base_from, char *base_to)
{
	return (ft_utoa_base(ft_atoi_base(str, base_from), base_to));
}
