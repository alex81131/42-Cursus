/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:34:02 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:01:31 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_ll_base(unsigned long n, char *base)
{
	static char	buf[18] = {0};
	int			i;
	int			lbase;

	lbase = ft_strlen(base);
	i = 16;
	while (1)
	{
		buf[i--] = base[n % lbase];
		n /= lbase;
		if (n == 0)
			break ;
	}
	return (ft_strdup(buf + 1 + i));
}
