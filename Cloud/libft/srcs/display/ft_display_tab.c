/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 09:09:58 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:04:11 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_display_tab(char **tab, char *tabname)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s[%u]\t: %s\n", tabname, i, tab[i]);
		i++;
	}
}
