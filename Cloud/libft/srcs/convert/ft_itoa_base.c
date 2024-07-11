/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:51:26 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:01:26 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int n, char *base)
{
	static char	buf[12] = {0};
	int			i;
	int			neg;
	int			lbase;

	lbase = ft_strlen(base);
	neg = n < 0 ? -1 : 1;
	i = 10;
	neg = (n < 0 ? -1 : 1);
	while (1)
	{
		buf[i--] = base[n % lbase];
		n /= lbase;
		if (n == 0)
			break ;
	}
	if (neg == -1)
		buf[i] = '-';
	return (neg == -1 ? ft_strdup(buf + i) : ft_strdup(buf + 1 + i));
}
