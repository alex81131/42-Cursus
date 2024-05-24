/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:55:22 by kyeh              #+#    #+#             */
/*   Updated: 2024/05/21 11:03:35 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit(int n)
{
	int	digit;

	digit = 0;
	if (n <= 0)
		digit++;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_inttochar(char *str, unsigned int m, int len)
{
	if (m == 0)
		str[0] = '0';
	while (m > 0)
	{
		str[len--] = (m % 10) + 48;
		m /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	m;

	len = ft_digit(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		m = n * -1;
	}
	else
		m = n;
	str = ft_inttochar(str, m, len);
	return (str);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*nb;

	nb = ft_itoa(n);
	len = ft_putstr(nb);
	free(nb);
	return (len);
}
