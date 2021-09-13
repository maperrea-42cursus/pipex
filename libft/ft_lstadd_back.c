/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:31:54 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/15 15:36:44 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	if (!(*list))
		(*list) = new;
	else
	{
		while ((*list)->next)
			list = &((*list)->next);
		(*list)->next = new;
	}
}
