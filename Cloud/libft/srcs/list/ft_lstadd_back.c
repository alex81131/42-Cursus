/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:02:17 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:04:57 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *list;

	if (alst == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	list = *alst;
	if (new != NULL)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
}
