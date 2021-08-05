/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:08:06 by pyasuko           #+#    #+#             */
/*   Updated: 2021/08/02 20:44:40 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	q;

	i = 0;
	if (n[i] == '\0')
		return ((char *)h);
	while (h[i] && i < len != '\0')
	{
		q = 0;
		while (n[q] != '\0')
		{
			if (i + q >= len || h[i + q] != n[q])
				break ;
			q++;
		}
		if (n[q] == '\0')
			return ((char *)(h + i));
		i++;
	}
	return (NULL);
}
