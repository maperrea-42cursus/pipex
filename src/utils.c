/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:27:27 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/13 17:03:05 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	array_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	error_exit(char *error)
{
	ft_putstr_fd(error, 1);
	free_list();
	exit(1);
}
