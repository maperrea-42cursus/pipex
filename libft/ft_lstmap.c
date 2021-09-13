/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:52:21 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 00:27:58 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new;

	map = NULL;
	while (list && list->content)
	{
		new = ft_lstnew((*f)(list->content));
		if (!new)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, new);
		list = list->next;
	}
	return (map);
}
