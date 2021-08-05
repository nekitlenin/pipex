/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:40:02 by pyasuko           #+#    #+#             */
/*   Updated: 2021/08/05 15:26:41 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != 0)
			return (env[i] + 5);
	}
	return (NULL);
}

char	*pars_path(char *path, char *com)
{
	char	**pathway;
	char	*way;
	int		i;

	i = -1;
	pathway = ft_split(path, ':');
	while (pathway[++i])
	{
		if (com[0] == '/')
			way = ft_sstrjoin(pathway[i], com, 1, 0);
		else
			way = ft_sstrjoin(ft_sstrjoin(pathway[i], "/", 1, 0), com, 1, 0);
		if (!access(way, F_OK))
		{
			// free(com);
			return (way);
		}
		free(way);
	}
	// free(com);
	free(way);
	free(pathway);
	return (NULL);
}

int	init(int argc, char **argv, char **envp, t_data *data)
{
	if (argc != 5)
	{
		ft_exit("Args! Example: ./pipex file1 cmd1 cmd2 file2");
		return (0);
	}
	data->file1 = argv[1];
	data->file2 = argv[4];
	data->com1 = ft_split(argv[2], ' ');
	if (!data->com1)
		ft_exit("Wrong 1 command");
	data->com2 = ft_split(argv[3], ' ');
	if (!data->com2)
		ft_exit("Wrong 2 command");
	data->path = NULL;
	data->path = get_path(envp);
	if (!data->path)
		ft_exit("Can't find path");
	return (1);
}

void	main_2(char *way, t_data *data, char **envp, int *fd)
{
	close(fd[1]);
	way = pars_path(data->path, data->com2[0]);
	while(1)
		write(1, "1\n", 2);
	if (!way)
		ft_exit("Wrong command 2");
	ft_parent(fd[0], way, envp, data);
	free(way);
}

int	main(int argc, char **argv, char **envp)
{
	int		pid;
	int		fd[2];
	char	*way;
	t_data	data;

	way = NULL;
	init(argc, argv, envp, &data);
	if (pipe(fd))
		ft_exit("Create pipe");
	pid = fork();
	if (pid == -1)
		ft_exit("Pid error");
	else if (pid == 0)
	{
		close(fd[0]);
		way = pars_path(data.path, data.com1[0]);
		while(1)
			write(1, "1\n", 2);
		if (!way)
			ft_exit("Wrong command 1");
		ft_child(fd[1], way, envp, &data);
		free(way);
	}
	else if (pid > 0)
		main_2(way, &data, envp, fd);
	return (1);
}
