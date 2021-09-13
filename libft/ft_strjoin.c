/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:14:12 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 00:05:02 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = malloc_list(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	(void)ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	(void)ft_strlcat(new, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (new);
}
