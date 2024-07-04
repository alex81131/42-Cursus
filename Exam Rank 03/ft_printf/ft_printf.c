#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i = 0;

	if (!str)
		ft_putstr("(null)");
	else
		while (str[i])
			ft_putchar(str[i++]);
	return (i);
}

int	ft_digit(int n)
{
	int	i = 0;

	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len = ft_digit(n);
	char		*str;
	unsigned int	nb;

	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}

int	ft_putnbr(int n)
{
	char		*str;
	int			len;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_puthex(unsigned int n)
{
	int	len = 0;

	if (n < 16)
	{
		if (n < 10)
			len += ft_putchar(n + '0');
		else
			len += ft_putchar(n - 10 + 'a');
	}
	else
	{
		len += ft_puthex(n / 16);
		len += ft_puthex(n % 16);
	}
	return (len);
}

int	input(va_list vl, const char format)
{
	int	n = 0;

	if (format == 's')
		n += ft_putstr(va_arg (vl, char *));
	else if (format == 'd')
		n += ft_putnbr(va_arg (vl, int));
	else if (format == 'x')
		n += ft_puthex(va_arg (vl, unsigned int));
	else if (format == '%')
		n += ft_putchar('%');
	return (n);
}

int	ft_printf(const char *format, ...)
{
	va_list	vl;
	int		i = 0;
	int		printed = 0;

	va_start(vl, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			printed += input(vl, format[i + 1]);
			i++;
		}
		else
			printed += ft_putchar(format[i]);
		i++;
	}
	va_end(vl);
	return (printed);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;

	printf("[ft_printf]\n");
	i = ft_printf("s: %s, d: %d, x: %x.\n", "Eleonore", -2147483648, 635);
	ft_printf("Word count = %d\n\n", i);
	printf("[printf]\n");
	j = printf("s: %s, d: %ld, x: %x.\n", "Eleonore", -2147483648, 635);
	printf("Word count = %d\n", j);
	return (0);
}
*/