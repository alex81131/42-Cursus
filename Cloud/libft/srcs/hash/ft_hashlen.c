/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:30:34 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/18 08:33:14 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hashlen(t_hash *hash)
{
	size_t	i;

	i = 0;
	while (hash)
	{
		hash = hash->next;
		i++;
	}
	return (i);
}
