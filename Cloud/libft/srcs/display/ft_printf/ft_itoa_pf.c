/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 09:18:12 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:02:53 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_pf(int n, t_printf *pf)
{
	static char	buf[12] = {0};
	int			i;
	int			neg;

	i = 10;
	if (n == -2147483648)
	{
		pf->sign = 1;
		return (ft_strdup("-2147483648"));
	}
	neg = n < 0 ? -1 : 1;
	n = n < 0 ? -n : n;
	while (1)
	{
		buf[i--] = n % 10 + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	if (neg == -1)
	{
		buf[i] = '-';
		pf->sign = 1;
	}
	return (neg == -1 ? ft_strdup(buf + i) : ft_strdup(buf + 1 + i));
}
