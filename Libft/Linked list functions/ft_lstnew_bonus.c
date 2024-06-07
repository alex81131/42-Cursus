/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:54:04 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/07 14:07:00 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
int main(void)
{
    char *content = "Hello, world!";
    t_list *new = ft_lstnew(content);

	if (new->content == content)
        printf("Content is correctly set to: %s\n", (char *)new->content);
	free(new);
	return 0;
}
*/