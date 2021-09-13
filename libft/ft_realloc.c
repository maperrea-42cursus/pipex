/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:55:18 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 00:24:41 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **ptr, size_t orig_size, size_t new_size)
{
	void	*tmp;

	tmp = ft_calloc(1, new_size);
	if (!tmp)
		return (NULL);
	if (orig_size < new_size)
		ft_memcpy(tmp, *ptr, orig_size);
	else
		ft_memcpy(tmp, *ptr, new_size);
	free_one(*ptr);
	*ptr = tmp;
	return (tmp);
}
