/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 09:58:01 by coscialp          #+#    #+#             */
/*   Updated: 2020/02/17 12:58:02 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hash_revsort_value(t_hash **alst, t_hash *hash)
{
	t_hash	tmp;
	t_hash	*adress;

	adress = *alst;
	while (hash->next)
	{
		if (ft_strcmp(hash->value, hash->next->value) < 0)
		{
			tmp.key = hash->key;
			tmp.value = hash->value;
			hash->key = hash->next->key;
			hash->value = hash->next->value;
			hash->next->key = tmp.key;
			hash->next->value = tmp.value;
			hash = adress;
			continue ;
		}
		hash = hash->next;
	}
}

void	ft_hash_revsort_key(t_hash **alst, t_hash *hash)
{
	t_hash	tmp;
	t_hash	*adress;

	adress = *alst;
	while (hash->next)
	{
		if (ft_strcmp(hash->key, hash->next->key) < 0)
		{
			tmp.key = hash->key;
			tmp.value = hash->value;
			hash->key = hash->next->key;
			hash->value = hash->next->value;
			hash->next->key = tmp.key;
			hash->next->value = tmp.value;
			hash = adress;
			continue ;
		}
		hash = hash->next;
	}
}

void	ft_hash_sort_value(t_hash **alst, t_hash *hash)
{
	t_hash	tmp;
	t_hash	*adress;

	adress = *alst;
	while (hash->next)
	{
		if (ft_strcmp(hash->value, hash->next->value) > 0)
		{
			tmp.key = hash->key;
			tmp.value = hash->value;
			hash->key = hash->next->key;
			hash->value = hash->next->value;
			hash->next->key = tmp.key;
			hash->next->value = tmp.value;
			hash = adress;
			continue ;
		}
		hash = hash->next;
	}
}

void	ft_hash_sort_key(t_hash **alst, t_hash *hash)
{
	t_hash	tmp;
	t_hash	*adress;

	adress = *alst;
	while (hash->next)
	{
		if (ft_strcmp(hash->key, hash->next->key) > 0)
		{
			tmp.key = hash->key;
			tmp.value = hash->value;
			hash->key = hash->next->key;
			hash->value = hash->next->value;
			hash->next->key = tmp.key;
			hash->next->value = tmp.value;
			hash = adress;
			continue ;
		}
		hash = hash->next;
	}
}
