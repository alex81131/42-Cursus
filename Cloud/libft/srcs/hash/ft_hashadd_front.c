/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:58:04 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 17:13:55 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hashadd_front(t_hash **hash, t_hash *new)
{
	if (new)
	{
		new->next = *hash;
		*hash = new;
	}
}
