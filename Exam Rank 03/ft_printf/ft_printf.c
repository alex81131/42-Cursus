#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i = 0;

	if (!str)
		i += ft_putstr("(null)");
	else
		while (str[i])
			ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				len = 0;

	if (n < 0)
	{
		len += ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	if (nb < 10)
		len += ft_putchar(nb + '0');
	else
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
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

int	ft_input(va_list vl, const char format)
{
	int	len = 0;

	if (format == 's')
		len += ft_putstr(va_arg(vl, char *));
	else if (format == 'd')
		len += ft_putnbr(va_arg(vl, int));
	else if (format == 'x')
		len += ft_puthex(va_arg(vl, unsigned int));
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i = 0;
	va_list	vl;
	int		len = 0;

	va_start(vl, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_input(vl, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(vl);
	return (len);
}
/*
#include <stdio.h>
#include <limits.h>

int	main()
{
	int	i;
	int	j;
 	char	*str = NULL;

	i = printf("%s, %s, %d, %x\n", "Eleonore", str, INT_MIN, 653);
	printf("%d\n", i);
	j = ft_printf("%s, %s, %d, %x\n", "Eleonore", str, INT_MIN, 653);
	printf("%d\n", j);
	return (0);
}
*/
