/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:19:17 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/12 23:53:04 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	size;
	char	*new;

	if (!str || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(str);
	while (str[start] && in_set(str[start], set))
		start++;
	while ((end) > 0 && in_set(str[end - 1], set))
		end--;
	size = end - start + 1;
	if (start > end)
		size = 1;
	new = malloc_list(sizeof(char) * size);
	if (!new)
		return (NULL);
	(void)ft_strlcpy(new, &(str[start]), size);
	return (new);
}
