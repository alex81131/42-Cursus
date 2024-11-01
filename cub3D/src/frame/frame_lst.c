/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:50:05 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/09 17:19:28 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frame.h"

t_frame	*frame_lstnew(void)
{
	t_frame	*lst;

	lst = (t_frame *)malloc(sizeof(t_frame));
	if (!lst)
		return (NULL);
	lst->before = NULL;
	lst->next = NULL;
	return (lst);
}

t_frame	*frame_lstlast(t_frame *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	frame_lstadd_back(t_frame **lst, t_frame *new)
{
	t_frame	*last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = frame_lstlast(*lst);
		last->next = new;
		new->before = last;
	}
	else
		*lst = new;
}

void	frame_lstclear(t_frame **lst, void (*del)(void *))
{
	t_frame	*node;

	if (!lst)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		del(*lst);
		*lst = node;
	}
}

int	frame_lstsize(t_frame *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
