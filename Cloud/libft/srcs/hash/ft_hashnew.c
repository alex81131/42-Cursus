/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:33:26 by coscialp          #+#    #+#             */
/*   Updated: 2020/04/22 15:06:52 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*get_value_alloc(void *value, char *type)
{
	if (!ft_strcmp(type, "string"))
		return (ft_strdup(value));
	return (NULL);
}

t_hash			*ft_hashnew(char *key, void *value, char *type)
{
	t_hash *hash;

	if (!(hash = (t_hash *)malloc(sizeof(t_hash) * 1)))
		return (NULL);
	hash->key = ft_strdup(key);
	hash->value = get_value_alloc(value, type);
	hash->top = hash;
	hash->before = NULL;
	hash->next = NULL;
	hash->type = type;
	hash->del = ft_hashdel;
	hash->print = ft_hash_display;
	hash->add_back = ft_hashadd_back;
	hash->add_front = ft_hashadd_front;
	hash->del_all = ft_hash_free;
	hash->search = ft_hash_search_value;
	hash->len = ft_hashlen;
	hash->change = ft_hash_change_value;
	hash->sort_key = ft_hash_sort_key;
	hash->rsort_val = ft_hash_revsort_key;
	hash->sort_val = ft_hash_sort_value;
	hash->rsort_val = ft_hash_revsort_value;
	hash->find = ft_hash_find;
	return (hash);
}
