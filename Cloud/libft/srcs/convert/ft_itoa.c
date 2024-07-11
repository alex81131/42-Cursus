/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:05:10 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:01:46 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	static char	buf[12] = {0};
	int			i;
	int			neg;

	i = 10;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0 ? -1 : 1);
	n = n < 0 ? -n : n;
	while (1)
	{
		buf[i--] = n % 10 + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	if (neg == -1)
		buf[i] = '-';
	return (neg == -1 ? ft_strdup(buf + i) : ft_strdup(buf + 1 + i));
}
