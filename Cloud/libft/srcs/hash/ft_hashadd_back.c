/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:13:29 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 18:24:59 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hashadd_back(t_hash **hash, t_hash *new)
{
	t_hash	*iter;
	t_hash	*before;

	if (!hash)
		return ;
	if (!(*hash))
		*hash = new;
	else if (new)
	{
		iter = *hash;
		while (iter->next)
			iter = iter->next;
		before = iter;
		iter->next = new;
		iter = iter->next;
		iter->top = *hash;
		iter->before = before;
	}
}
