/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_search_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:54:32 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/19 14:17:19 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_hash_search_value(t_hash *hash, char *key)
{
	while (hash)
	{
		if (!ft_strcmp(hash->key, key))
			return (hash->value);
		hash = hash->next;
	}
	return (NULL);
}
