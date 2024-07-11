/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:02:00 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:07:15 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strfjoin(char *s1, char *s2, int free)
{
	char	*str;

	if (!(str = ft_strjoin(s1, s2)))
		return (0);
	if (free == 1)
		ft_strdel(&s1);
	else if (free == 2)
		ft_strdel(&s2);
	else if (free == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}
