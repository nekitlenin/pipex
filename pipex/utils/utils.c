/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:36:19 by pyasuko           #+#    #+#             */
/*   Updated: 2021/08/05 15:12:48 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	my_free(char **s)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while(s[++i][j])
	{
		j = 0;
			while(s[i][j++])
				free(*s);
	}
}

void	ft_exit(char *err)
{
	printf("\x1B[31mFailed: \x1b[0m%s\n", err);
	exit(1);
}

int	ft_child(int fd, char *way, char **envp, t_data *data)
{
	int	dup;

	dup = open(data->file1, O_RDONLY, 0777);
	if (dup == -1)
		ft_exit("Read file 1");
	dup2(dup, 0);
	close(dup);
	dup2(fd, 1);
	close(fd);
	if (execve(way, data->com1, envp) == -1)
		ft_exit("Run command 1");
	return (0);
}

int	ft_parent(int fd, char *way, char **envp, t_data *data)
{
	int	dup;

	dup = open(data->file2, O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (dup == -1)
		ft_exit("Read file 2");
	dup2(fd, 0);
	close(fd);
	dup2(dup, 1);
	close(dup);
	if (execve(way, data->com2, envp) == -1)
		ft_exit("Run command 2");
	return (0);
}
