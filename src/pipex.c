/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:20:57 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/13 17:58:38 by maperrea         ###   ########.fr       */
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

void	set_path(t_command *command, int proc, char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!access(command->proc[proc].path, F_OK))
		return ;
	while (path[i])
	{
		tmp = ft_strdup(path[i]);
		if (path[i][ft_strlen(path[i]) - 1] != '/')
			tmp = ft_strjoin(tmp, "/");
		tmp = ft_strjoin(tmp, command->proc[proc].path);
		if (!access(tmp, F_OK))
			break ;
		i++;
	}
	if (!path[i])
		error_exit("Error: cmd not found\n");
	if (!access(tmp, X_OK))
		command->proc[proc].path = tmp;
	else
		error_exit("Error: no execution permissions\n");
}

void	get_proc_path(t_command *command, char **envp)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_split(&(envp[i][5]), ':');
			break ;
		}
		i++;
	}
	i = 0;
	if (!path)
		error_exit("Error: no PATH env variable\n");
	set_path(command, 0, path);
	set_path(command, 1, path);
}

void	set_fd(t_command *command)
{
	int	fd[2];

	command->proc[0].in = open(command->infile, O_RDONLY);
	if (command->proc[0].in < 0)
		error_exit(strerror(errno));
	command->proc[1].out = open(command->outfile,
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (command->proc[1].out < 0)
	{
		close(command->proc[0].in);
		error_exit(strerror(errno));
	}
	if (pipe(fd))
	{
		close(command->proc[0].in);
		close(command->proc[1].in);
		error_exit(strerror(errno));
	}
	command->proc[0].out = fd[1];
	command->proc[1].in = fd[0];
}

int	main(int argc, char **argv, char **envp)
{
	t_command	command;

	if (argc != 5)
		error_exit("Error: wrong number of arguments\n");
	parse_argv(argv, &command);
	get_proc_path(&command, envp);
	set_fd(&command);
	printf("%s\n%s\n", command.proc[0].path, command.proc[1].path);
	printf("%d | %d | %d | %d\n", command.proc[0].in, command.proc[0].out, command.proc[1].in, command.proc[1].out);
}
