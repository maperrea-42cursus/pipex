/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:20:46 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/13 17:57:19 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_proc
{
	char	*path;
	char	**argv;
	int		in;
	int		out;
}				t_proc;

typedef struct s_command
{
	t_proc	proc[2];
	char	*infile;
	char	*outfile;
}				t_command;

void			array_free(char **array);
void			error_exit(char *error);
#endif
