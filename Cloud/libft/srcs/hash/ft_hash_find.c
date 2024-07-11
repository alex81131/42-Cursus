/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 08:13:02 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/18 08:20:16 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash		*ft_hash_find(t_hash *hash, char *key)
{
	if (hash)
		while (hash)
		{
			if (!ft_strcmp(hash->key, key))
				return (hash);
			hash = hash->next;
		}
	return (NULL);
}
