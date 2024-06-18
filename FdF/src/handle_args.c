/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:14:10 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/18 17:21:55 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_tolower_char(char *c)
{
	*c = ft_tolower(*c);
}

static int	parse_color(t_map *map, char *c)
{
	while (*c && (ft_isdigit(*c) || *s == '-' || *s == '+' || *s == ','))
		c++;
	if (*c && *c == 'x')
	{
		map->iscolor = 1;
		ft_striter(s + 1, ft_tolower_char);
		return (ft_atoi_base(s + 1, LHEX));
	}
	else 
		return (WHITE);
	return (0);
}
