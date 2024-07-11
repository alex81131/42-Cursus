/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:14:25 by coscialp          #+#    #+#             */
/*   Updated: 2020/03/03 16:27:08 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabjoin(char **t1, char **t2)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) *
	(ft_tablen(t1) + ft_tablen(t2) + 1))))
		return (NULL);
	while (t1[j])
	{
		tab[i] = ft_strdup(t1[j]);
		j++;
		i++;
	}
	j = 0;
	while (t2[j])
	{
		tab[i] = ft_strdup(t2[j]);
		i++;
		j++;
	}
	tab[i] = NULL;
	return (tab);
}
