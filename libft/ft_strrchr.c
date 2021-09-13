/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:57:33 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/12 23:54:29 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((char)c == 0)
		return ((char *)&(s[ft_strlen(s)]));
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&(s[i]));
		i--;
	}
	return (NULL);
}
