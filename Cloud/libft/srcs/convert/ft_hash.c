/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:04:59 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:28:58 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_strhash	*ft_strhash(char **key, char **value)
{
	t_strhash	*hash;
	size_t		lkey;
	size_t		i;

	lkey = 0;
	i = 0;
	while (key[lkey])
		lkey++;
	hash = (t_strhash *)malloc(sizeof(t_strhash) * (lkey + 1));
	while (i < lkey)
	{
		hash[i].key = ft_strdup(key[i]);
		hash[i].value = ft_strdup(value[i]);
		i++;
	}
	hash[i].key = NULL;
	hash[i].value = NULL;
	return (hash);
}

char		*ft_get_hash_value(t_strhash *hash, char *str)
{
	size_t	i;

	i = 0;
	while (hash[i].key)
	{
		if (!ft_strcmp(hash[i].key, str))
			return (hash[i].value);
		i++;
	}
	return (NULL);
}

void		*change_value(t_strhash *hash, char *str, char *new)
{
	size_t	i;

	i = 0;
	while (hash[i].key)
	{
		if (!ft_strcmp(hash[i].key, str))
		{
			free(hash[i].value);
			if (new)
				hash[i].value = ft_strdup(new);
			else
				hash[i].value = ft_strdup("");
		}
		i++;
	}
	return (NULL);
}
