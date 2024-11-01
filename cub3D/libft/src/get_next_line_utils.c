/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:38:15 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/31 19:15:50 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	copy_and_cat(char *out, char *cpy_src, char *cat_src)
{
	int	i;
	int	src_i;

	i = 0;
	src_i = 0;
	while (cpy_src[src_i])
	{
		out[i] = cpy_src[src_i];
		i++;
		src_i++;
	}
	src_i = 0;
	while (cat_src[src_i])
		out[i++] = cat_src[src_i++];
	out[i] = '\0';
}

int	find_eol(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
