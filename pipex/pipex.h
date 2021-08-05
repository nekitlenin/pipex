/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:44:26 by pyasuko           #+#    #+#             */
/*   Updated: 2021/08/04 19:18:13 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define	PIPEX_H

# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>

typedef struct s_data
{
	int			argc;
	char		**argv;
	char		**envp;
	char		*file1;
	char		*file2;
	char		*path;
	char		**com1;
	char		**com2;
}				t_data;

char	*ft_strnstr(const char *h, const char *n, size_t len);
char	*ft_sstrjoin(char *s1, char *s2, int f_s1, int f_s2);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);

void	my_free(char **s);
void	ft_exit(char *err);
int		ft_child(int fd, char *way, char **envp, t_data *data);
int		ft_parent(int fd, char *way, char **envp, t_data *data);

#endif