/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:54:37 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/18 08:26:00 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash		*ft_hash_init(void)
{
	static t_hash	hash;

	hash.before = NULL;
	hash.next = NULL;
	hash.del = ft_hashdel;
	hash.print = ft_hash_display;
	hash.add_back = ft_hashadd_back;
	hash.add_front = ft_hashadd_front;
	hash.del_all = ft_hash_free;
	hash.search = ft_hash_search_value;
	hash.len = ft_hashlen;
	hash.change = ft_hash_change_value;
	hash.new = ft_hashnew;
	hash.sort_key = ft_hash_sort_key;
	hash.rsort_val = ft_hash_revsort_key;
	hash.sort_val = ft_hash_sort_value;
	hash.rsort_val = ft_hash_revsort_value;
	hash.find = ft_hash_find;
	return (&hash);
}
