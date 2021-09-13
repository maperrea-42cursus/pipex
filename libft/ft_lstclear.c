/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:43:32 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/09 20:10:11 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*next;

	while (*list)
	{
		next = (*list)->next;
		ft_lstdelone(*list, del);
		*list = next;
	}
}
