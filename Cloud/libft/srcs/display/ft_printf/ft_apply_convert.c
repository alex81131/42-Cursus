/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:23:17 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:02:00 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_zero_str(char *tmp, t_printf *pf)
{
	if (ft_char_in_string(pf->option, "diuxX") && !ft_strncmp(tmp, "0", 1) &&
	pf->accu == 0 && ft_is_in_flags('.', pf))
	{
		ft_strdel(&tmp);
		return (ft_calloc(sizeof(char), 1));
	}
	return (tmp);
}

char			*ft_apply_convert(t_printf *pf, va_list ap)
{
	char *tmp;

	if (pf->option == 'c')
		tmp = ft_c_converter(va_arg(ap, int), pf);
	else if (pf->option == 'd' || pf->option == 'i')
		tmp = ft_d_converter(va_arg(ap, int), pf);
	else if (pf->option == 'p')
		tmp = ft_p_converter(va_arg(ap, long long), pf);
	else if (pf->option == 's')
		tmp = ft_s_converter(va_arg(ap, char *), pf->accu, pf->flags);
	else if (pf->option == 'u')
		tmp = ft_u_converter(va_arg(ap, unsigned int));
	else if (pf->option == 'X')
		tmp = ft_upx_converter(va_arg(ap, unsigned int));
	else if (pf->option == 'x')
		tmp = ft_x_converter(va_arg(ap, unsigned int));
	else if (pf->option == '%')
		tmp = ft_pourcent_converter();
	else
		tmp = ft_c_converter(pf->option, pf);
	return (ft_zero_str(tmp, pf));
}
