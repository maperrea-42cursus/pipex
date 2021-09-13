/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:01:36 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/12 23:34:08 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_malloc	*g_malloc_list;

void	*malloc_list(size_t size)
{
	void		*ptr;
	t_malloc	*new_malloc;
	t_malloc	*tmp;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	new_malloc = malloc(sizeof(t_malloc));
	if (!new_malloc)
		return (NULL);
	new_malloc->ptr = ptr;
	new_malloc->next = NULL;
	if (!g_malloc_list)
		g_malloc_list = new_malloc;
	else
	{
		tmp = g_malloc_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_malloc;
	}
	return (ptr);
}

void	free_one(void *ptr)
{
	t_malloc	*tmp;
	t_malloc	*next;

	tmp = g_malloc_list;
	while (tmp->next && tmp->next->ptr != ptr)
		tmp = tmp->next;
	if (tmp->next)
	{
		next = tmp->next->next;
		free(tmp->next->ptr);
		free(tmp->next);
		tmp->next = next;
	}
}

void	free_list(void)
{
	t_malloc	*next;

	while (g_malloc_list)
	{
		next = g_malloc_list->next;
		free(g_malloc_list->ptr);
		free(g_malloc_list);
		g_malloc_list = next;
	}
}
