/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:57:11 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/10 15:45:28 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_list	*read_map(char *line, t_data *data)
{
	t_list	*map_list;
	t_list	*new;

	map_list = NULL;
	while (line)
	{
		if (ft_strncmp(line, "\n", 1))
		{
			new = ft_lstnew(line);
			if (!new)
			{
				free(line);
				ft_lstclear(&map_list, free);
				return (NULL);
			}
			ft_lstadd_back(&map_list, new);
			if (ft_strlen(line) > data->map_width)
				data->map_width = ft_strlen(line);
		}
		else
			free(line);
		line = get_next_line(data->map_fd);
	}
	return (map_list);
}

char	**build_map(t_data *data, char *line)
{
	t_list	*map_list;
	t_list	*temp;
	char	**map;
	size_t	i;

	if (!line)
		return (NULL);
	map_list = read_map(line, data);
	if (!map_list)
		return (NULL);
	data->map_boundary = ft_lstsize(map_list);
	map = ft_calloc(data->map_boundary + 1, sizeof(char *));
	if (!map)
		return (ft_lstclear(&map_list, free), NULL);
	temp = map_list;
	i = 0;
	while (temp)
	{
		map[i++] = (char *)temp->content;
		temp = temp->next;
	}
	map[i] = NULL;
	ft_lstclear_no_content(&map_list);
	return (map);
}
