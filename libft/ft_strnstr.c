/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:14:11 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/12 23:53:44 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (i < n && s1[i])
	{
		j = 0;
		while (i + j < n && s2[j] && s1[i + j] == s2[j])
			j++;
		if (!s2[j])
			return ((char *)&(s1[i]));
		i++;
	}
	return (NULL);
}
