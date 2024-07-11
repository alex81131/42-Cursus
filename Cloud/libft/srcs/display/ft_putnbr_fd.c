/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:02:18 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:04:29 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	static char	buf[12] = {0};
	int			i;
	int			neg;

	i = 10;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
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
		buf[i] = '-';
	write(fd, buf + i + (neg != -1), 11 - i - (neg != -1));
}
