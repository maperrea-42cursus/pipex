/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:56:28 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 18:06:33 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start > (unsigned)ft_strlen(s))
		return (ft_calloc(1, 1));
	if (ft_strlen(&(s[start])) < len)
		len = ft_strlen(&(s[start]));
	sub = malloc_list(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	(void)ft_strlcpy(sub, &(s[start]), len + 1);
	return (sub);
}
