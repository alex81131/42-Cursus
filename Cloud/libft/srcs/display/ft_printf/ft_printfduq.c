/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfduq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:46:11 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:03:17 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf	*setup_struct(void)
{
	t_printf *setup;

	if (!(setup = malloc(sizeof(t_printf))))
		return (NULL);
	setup->width = 0;
	setup->option = 0;
	setup->accu = 0;
	setup->zero = 0;
	setup->sign = 0;
	setup->return_size = 0;
	setup->current_size = 0;
	ft_bzero(setup->flags, 5);
	return (setup);
}

static char		*ft_join_result(char *result, char *tmp, t_printf *pf)
{
	char	*s;

	if (pf->option == 'c' && pf->zero == 1)
	{
		if (!(s = ft_memjoin(result, tmp, pf->return_size, pf->current_size)))
			return (NULL);
	}
	else
	{
		if (!(s = ft_memjoin(result, tmp, pf->return_size, pf->current_size)))
			return (NULL);
	}
	ft_strdel(&result);
	ft_strdel(&tmp);
	pf->zero = 0;
	pf->return_size += pf->current_size;
	return (s);
}

static char		**ft_set_tmp(const char *str)
{
	char	**tmp;
	size_t	i;
	size_t	j;

	if (!(tmp = malloc(sizeof(char *) * 4)))
		return (NULL);
	i = 1;
	while (ft_isdigit(str[i]) || ft_is_flag(str[i]))
		i++;
	i++;
	j = i;
	while (str[j] && str[j] != '%')
		j++;
	if (!((tmp[0] = ft_strndup(str, i))))
		return (NULL);
	if (!(tmp[1] = ft_strndup(str + i, j - i)))
		return (NULL);
	return (tmp);
}

int				coreducul(char *s, size_t pos, t_printf *pf, va_list ap)
{
	char		**tmp;
	char		*result;

	result = ft_strndup(s, pos);
	s += pos;
	pf->return_size += pos;
	while (*s)
	{
		pf->current_size = 0;
		pf->zero = 0;
		if (!(tmp = ft_set_tmp(s)))
			return (-1);
		s += ft_strlen(tmp[0]) + ft_strlen(tmp[1]);
		if (!(tmp[2] = ft_strfjoin(tmp[0], tmp[1], 3)))
			return (-1);
		if (!(tmp[3] = ft_analyser(tmp[2], pf, ap)))
			return (-1);
		free(tmp[2]);
		if (!(result = ft_join_result(result, tmp[3], pf)))
			return (-1);
		free(tmp);
	}
	write(1, result, pf->return_size - 1);
	free(result);
	return (pf->return_size);
}

int				ft_printfducul(char *s, ...)
{
	va_list		ap;
	size_t		pos;
	t_printf	*pf;

	pos = 0;
	va_start(ap, s);
	if (!(pf = setup_struct()))
		return (-1);
	if (!ft_memchr(s, '%', ft_strlen(s)))
	{
		write(1, s, (ft_strlen(s) - (size_t)1));
		ft_putstr(" du cul\n");
		va_end(ap);
		free(pf);
		return (ft_strlen(s) + 9);
	}
	pos = (char *)ft_memchr(s, '%', ft_strlen(s)) - s;
	pos = coreducul(s, pos, pf, ap);
	if (pos == (size_t)-1)
		return (-1);
	va_end(ap);
	free(pf);
	ft_putstr(" du cul\n");
	return (pos);
}
