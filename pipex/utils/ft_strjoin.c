/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:09:29 by pyasuko           #+#    #+#             */
/*   Updated: 2021/08/04 20:37:50 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
		n++;
	}
	i = -1;
	while (s2[++i] != '\0')
	{
		s3[n] = s2[i];
		n++;
	}
	s3[n] = '\0';
	return (s3);
}

char	*ft_sstrjoin(char *s1, char *s2, int f_s1, int f_s2)
{
	char	*old_s1;
	char	*old_s2;

	old_s1 = s1;
	old_s2 = s2;
	s1 = ft_strjoin(s1, s2);
	if (f_s1)
		free(old_s1);
	if (f_s2)
		free(old_s2);
	return (s1);
}