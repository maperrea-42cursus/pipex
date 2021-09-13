/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 23:22:56 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 00:20:42 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_str(char *str)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	j = ft_strlen(str);
	out = malloc_list(j + 1);
	if (!out)
		return (NULL);
	while (i < ft_strlen(str))
		out[i++] = str[--j];
	out[i] = 0;
	return (out);
}
