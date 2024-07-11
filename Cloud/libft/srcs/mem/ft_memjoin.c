/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:33:29 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:05:56 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *s1, void *s2, size_t size1, size_t size2)
{
	char	*rslt;

	rslt = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		rslt = ft_calloc(sizeof(char), size2);
		ft_memmove(rslt, s2, size2);
		return ((void *)rslt);
	}
	if (!s2)
	{
		rslt = ft_calloc(sizeof(char), size1);
		ft_memmove(rslt, s1, size1);
		return ((void *)rslt);
	}
	rslt = ft_calloc(sizeof(char), size1 + size2);
	ft_memmove(rslt, s1, size1);
	ft_memmove(rslt + size1, s2, size2);
	return ((void *)rslt);
}
