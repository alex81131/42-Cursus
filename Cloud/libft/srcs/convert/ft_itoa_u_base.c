/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:22:50 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:01:40 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_u_base(unsigned int n, char *base)
{
	static char	buf[12] = {0};
	int			i;
	int			lbase;

	lbase = ft_strlen(base);
	i = 10;
	while (1)
	{
		buf[i--] = base[n % lbase];
		n /= lbase;
		if (n == 0)
			break ;
	}
	return (ft_strdup(buf + 1 + i));
}
