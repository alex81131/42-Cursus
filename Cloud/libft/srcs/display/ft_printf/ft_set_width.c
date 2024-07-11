/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:46:02 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:03:41 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_wildcard(int nb, t_printf *pf)
{
	size_t	i;

	i = ft_strlen(pf->flags);
	if (nb < 0)
	{
		if (!ft_char_in_string('-', pf->flags))
			pf->flags[i] = '-';
		if (nb == -2147483648)
			return (2147483648);
		nb = -nb;
	}
	return (nb);
}

size_t		ft_width(char *str, t_printf *pf, va_list ap, size_t i)
{
	if (str[i] == '*')
	{
		pf->width = ft_wildcard(va_arg(ap, int), pf);
		i++;
	}
	else
	{
		pf->width = ft_atoi(str + i);
		while (ft_isdigit(str[i]) && !ft_is_option(str[i]))
			i++;
	}
	return (i);
}

size_t		ft_accu(char *str, t_printf *pf, va_list ap, size_t i)
{
	int		nb;

	i++;
	nb = 0;
	if (str[i] == '*')
	{
		nb = va_arg(ap, int);
		if (nb < 0)
			pf->accu = (size_t)-1;
		else
			pf->accu = ft_wildcard(nb, pf);
		i++;
	}
	else
	{
		pf->accu = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

char		*ft_set_width(char *str, t_printf *pf, va_list ap, size_t i)
{
	while (str[i] && (ft_is_flag(str[i]) || ft_isdigit(str[i])))
	{
		if (str[i] == '.')
			i = ft_accu(str, pf, ap, i);
		else
			i = ft_width(str, pf, ap, i);
	}
	return (str + i);
}
