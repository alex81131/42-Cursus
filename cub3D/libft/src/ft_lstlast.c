/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:55:17 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/03 13:25:07 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node->next)
		node = node->next;
	return (node);
}
/* This function acts under the scope of function, meaning any change,
ie. iteration, will only take effect within this function.
It will NOT impact the original list, which is outside the function,
because it takes *lst instead of **lst as the argument,
where the latter WILL modify the real list, modifying the pointer to the
pointer that stores the head of the list.

So the function below is functionally equivalent to the above:
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
*/