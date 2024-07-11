/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:08:07 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:05:52 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_memfjoin(void *s1, void *s2, size_t size1, size_t size2)
{
	char	*str;

	if (!(str = ft_memjoin(s1, s2, size1, size2)))
		return (0);
	ft_strdel((char **)&s1);
	ft_strdel((char **)&s2);
	return (str);
}
