/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:48:20 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/10 15:55:57 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	add_floor_ceiling(char *line, t_texture_data *texture)
{
	if (!ft_strncmp(line, "F ", 2))
		return (cub_atoi(line, texture, &texture->floor));
	else if (!ft_strncmp(line, "C ", 2))
		return (cub_atoi(line, texture, &texture->ceiling));
	return (FAILURE);
}

static int	check_element(char *line, t_texture_data *texture)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (add_data_buff(line, texture, N));
	else if (!ft_strncmp(line, "SO ", 3))
		return (add_data_buff(line, texture, S));
	else if (!ft_strncmp(line, "EA ", 3))
		return (add_data_buff(line, texture, E));
	else if (!ft_strncmp(line, "WE ", 3))
		return (add_data_buff(line, texture, W));
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (add_floor_ceiling(line, texture));
	else if (!ft_strncmp(line, "D ", 2))
		return (add_data_buff(line, texture, D));
	else if (!ft_strncmp(line, "\n", 2))
		return (SUCCESS);
	else
		return (FAILURE);
	return (SUCCESS);
}

static int	parse_texture_line(char **line, \
								t_texture_data *texture, t_data *data)
{
	while (*line && texture->nb < TEXTURE_NB)
	{
		if (check_element(*line, texture) == FAILURE)
		{
			free(*line);
			*line = NULL;
			cub_free_texture(texture);
			return (FAILURE);
		}
		free(*line);
		*line = get_next_line(data->map_fd);
	}
	if (!*line)
	{
		cub_free_texture(texture);
		return (FAILURE);
	}
	return (SUCCESS);
}

t_texture_data	*get_texture_data(t_data *data, char **line)
{
	t_texture_data	*texture;

	texture = ft_calloc(1, sizeof(t_texture_data));
	if (!texture)
		return (NULL);
	if (parse_texture_line(line, texture, data) == FAILURE)
		return (NULL);
	if (check_texture_path(texture->path) == FAILURE)
	{
		cub_free_texture(texture);
		return (NULL);
	}
	return (texture);
}
