/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:27:27 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/21 18:09:33 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_argv(char **argv, t_command *command)
{
	char	**tmp;

	command->infile = argv[1];
	command->outfile = argv[4];
	tmp = ft_split(argv[2], ' ');
	if (!tmp)
		error_exit("Error: malloc failed\n");
	command->proc[0].path = ft_strdup(tmp[0]);
	command->proc[0].argv = tmp;
	tmp = ft_split(argv[3], ' ');
	if (!tmp)
	{
		free_one(command->proc[0].path);
		array_free(command->proc[0].argv);
		error_exit("Error: malloc failed\n");
	}
	command->proc[1].path = ft_strdup(tmp[0]);
	command->proc[1].argv = tmp;
}

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
	ft_putstr_fd(error, 2);
	free_list();
	exit(1);
}
