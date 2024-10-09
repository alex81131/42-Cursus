/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:18:59 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/02 18:53:28 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	convert_nb(char *line, int	*rgb, size_t *i, size_t *array_i)
{
	int	nb;

	nb = 0;
	while (ft_isdigit(line[*i]))
	{
		nb = 10 * nb + (line[*i] - '0');
		rgb[*array_i] = nb;
		if (rgb[*array_i] > 255)
			return (FAILURE);
		(*i)++;
	}
	(*array_i)++;
	return (SUCCESS);
}

int	cub_atoi(char *line, t_texture_data *texture, int *color)
{
	size_t	i;
	size_t	array_i;
	int		rgb[3];

	i = 2;
	array_i = 0;
	while (line[i] && line[i] != '\n' && array_i < 3)
	{
		while (line[i] == ' ')
			i++;
		if (ft_isdigit(line[i]))
			convert_nb(line, rgb, &i, &array_i);
		else
			return (FAILURE);
		while (line[i] == ' ')
			i++;
		if (line[i] && (line[i] != ',' && (array_i != 3 && line[i] == '\n')))
			return (FAILURE);
		i++;
	}
	if (array_i != 3 || line[i] != '\0')
		return (FAILURE);
	texture->nb++;
	*color = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	return (SUCCESS);
}

int	add_data_buff(char *line, t_texture_data *texture, t_texture type)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = ft_strlen(line) - 1;
	if (texture->path[type])
		return (FAILURE);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	while (end > 0 && line[end] == ' ')
		end--;
	texture->path[type] = ft_substr(line, i, end - i);
	texture->nb++;
	return (SUCCESS);
}

int	check_texture_path(char **path)
{
	size_t	i;

	i = 0;
	while (i < TEXTURE_PATH)
	{
		if (!path[i])
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

void	free_texture(t_texture_data *texture)
{
	size_t	i;

	i = 0;
	while (i < TEXTURE_PATH)
	{
		if (texture->path[i])
			free(texture->path[i]);
		i++;
	}
	free(texture);
}
