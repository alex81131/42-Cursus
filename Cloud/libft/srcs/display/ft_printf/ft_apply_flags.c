/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:30:58 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:02:10 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_del_neg(char *str)
{
	char		*tmp;

	if (!(tmp = ft_calloc(sizeof(char), (ft_strlen(str)))))
		return (NULL);
	ft_memcpy(tmp, str + 1, ft_strlen(str));
	ft_memcpy(str, tmp, ft_strlen(tmp) + 1);
	ft_strdel(&tmp);
	return (str);
}

char	*ft_apply_accu(char *str, t_printf *pf)
{
	char *tmp;

	if (pf->accu && pf->accu > (ft_strlen(str) - pf->sign))
	{
		if (pf->sign)
			str = ft_del_neg(str);
		if (!(tmp = ft_calloc(sizeof(char), (pf->accu - ft_strlen(str) + 1))))
			return ((char *)-1);
		if (pf->option != 'p' && pf->option != 's' && pf->option != '%')
		{
			ft_memset(tmp, '0', (pf->accu - ft_strlen(str)));
			if (pf->sign)
				tmp = ft_strfjoin("-", tmp, 2);
		}
		tmp = ft_strfjoin(tmp, str, 3);
	}
	else
	{
		tmp = ft_strdup(str);
		ft_strdel(&str);
	}
	return (tmp);
}

char	*ft_apply_minus(char *str, t_printf *pf)
{
	char	*tmp;
	int		l;

	l = ft_strlen(str);
	if (pf->width > ft_strlen(str))
	{
		if (!(tmp = ft_calloc(sizeof(char), (pf->width - l + 1 + pf->zero))))
			return ((char *)-1);
		ft_memset(tmp, ' ', (pf->width - ft_strlen(str) + pf->zero));
		tmp = ft_strfjoin(str, tmp, 3);
	}
	else
	{
		tmp = ft_strdup(str);
		ft_strdel(&str);
	}
	if (pf->zero)
	{
		tmp[0] = 0;
		pf->current_size = pf->width + !pf->width;
	}
	return (tmp);
}

char	*ft_apply_zero(char *str, t_printf *pf)
{
	char	*tmp;
	size_t	l;

	l = ft_strlen(str);
	if (pf->width > l)
	{
		if (!(tmp = ft_calloc(sizeof(char), (pf->width - l + 1 + pf->zero))))
			return ((char *)-1);
		if (ft_is_in_flags('0', pf) && !ft_is_in_flags('.', pf))
		{
			if (pf->sign)
				str = ft_del_neg(str);
			ft_memset(tmp, '0', (pf->width - ft_strlen(str) - pf->sign));
			if (pf->sign)
				tmp = ft_strfjoin("-", tmp, 2);
		}
		else
			ft_memset(tmp, ' ', (pf->width - ft_strlen(str) + pf->zero));
		tmp = ft_strfjoin(tmp, str, 1);
	}
	else
		tmp = ft_strdup(str);
	ft_strdel(&str);
	return (tmp);
}

char	*ft_apply_flags(char *str, t_printf *pf)
{
	if (ft_is_in_flags('.', pf) && ft_is_in_flags('*', pf) &&
	pf->accu == (size_t)-1)
		pf->accu = ft_strlen(str) - pf->sign;
	if (ft_is_in_flags('.', pf))
		str = ft_apply_accu(str, pf);
	if (ft_is_in_flags('-', pf))
		str = ft_apply_minus(str, pf);
	else
		str = ft_apply_zero(str, pf);
	if (pf->zero && pf->width > 1 && !ft_is_in_flags('-', pf))
	{
		str[pf->width - 1] = 0;
		pf->current_size = pf->width;
	}
	pf->sign = 0;
	return (str);
}
