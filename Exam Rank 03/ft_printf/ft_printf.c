/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:42:57 by kyeh              #+#    #+#             */
/*   Updated: 2024/07/02 17:07:53 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

//	s: strings
int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i = 0;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

//	d: integers
int	ft_digit(int n)
{
	int	digit = 0;

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
	int				len = ft_digit(n);
	unsigned int	m;

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

//	x: hexadecimals
int	hex_digit(unsigned int n)
{
	int	len = 0;

	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int n, const char format)
{
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			if (format == 'x')
				ft_putchar(n - 10 + 'a');
	}
	else
	{
		ft_put_hex(n / 16, format);
		ft_put_hex(n % 16, format);
	}
}

int	ft_puthex(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(n, format);
	return (hex_digit(n));
}

int	ft_input(va_list vl, const char format)
{
	int	n;

	n = 0;
	if (format == 's')
		n += ft_putstr(va_arg(vl, char *));
	else if (format == 'd' || format == 'i')
		n += ft_putnbr(va_arg(vl, int));
	else if (format == 'x')
		n += ft_puthex(va_arg(vl, unsigned int), format);
	else if (format == '%')
		n += ft_putchar('%');
	return (n);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	vl;
	int		char_printed;

	i = 0;
	char_printed = 0;
	va_start(vl, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_printed += ft_input(vl, format[i + 1]);
			i++;
		}
		else
			char_printed += ft_putchar(format[i]);
		i++;
	}
	va_end(vl);
	return (char_printed);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;

	i = ft_printf("s: %s, d: %d, x: %x.\n", "Eleonore", 635, 635);
	ft_printf("Word count = %d\n", i);
	j = printf("s: %s, d: %d, x: %x.\n", "Eleonore", 635, 635);
	printf("Word count = %d\n", j);
	return (0);
}
*/