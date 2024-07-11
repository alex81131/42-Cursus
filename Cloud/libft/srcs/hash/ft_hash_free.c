/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:49:49 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 19:38:46 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hash_free(t_hash **hash)
{
	t_hash *next;

	while (*hash)
	{
		next = (*hash)->next;
		(*hash)->del(hash, (*hash)->before, (*hash)->next);
		*hash = next;
	}
}
