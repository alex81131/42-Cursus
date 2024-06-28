/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:51:24 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/26 16:51:24 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_get_min_max_z(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->h)
	{
		x = -1;
		while (++x < map->w)
		{
			if (map->z_mt[y][x] < map->min_z)
				map->min_z = map->z_mt[y][x];
			if (map->z_mt[y][x] > map->max_z)
				map->max_z = map->z_mt[y][x];
		}
	}
}

void	fdf_free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->z_mt)
	{
		i = -1;
		while (++i < map->h)
			if (map->z_mt[i])
				free(map->z_mt[i]);
		free(map->z_mt);
	}
	if (map->clrs)
	{
		i = -1;
		while (++i < map->h)
			if (map->clrs[i])
				free(map->clrs[i]);
		free(map->clrs);
	}
	free(map);
}

void	fdf_alloc_map(t_map *map)
{
	int	i;

	map->z_mt = (int **)malloc(map->h * sizeof(int *));
	map->clrs = (int **)malloc(map->h * sizeof(int *));
	if (!map->z_mt || !map->clrs)
	{
		fdf_free_map(map);
		err_exit("Error", MAL_ERROR);
	}
	i = -1;
	while (++i < map->h)
	{
		map->z_mt[i] = (int *)malloc(map->w * sizeof(int));
		map->clrs[i] = (int *)malloc(map->w * sizeof(int));
		if (!map->z_mt[i] || !map->clrs[i])
		{
			fdf_free_map(map);
			err_exit("Error", MAL_ERROR);
		}
	}
}

static int	measure_width(t_map *map, char *line, char *file)
{
	int		count;
	char	**arr;

	if (!line)
	{
		fdf_free_map(map);
		err_exit(file, "is an empty map.");
	}
	arr = ft_split(line, ' ');
	if (!arr)
	{
		fdf_free_map(map);
		err_exit("Error", MAL_ERROR);
	}
	count = 0;
	while (arr[count])
		count++;
	free_array(arr);
	return (count);
}

t_map	*fdf_initialize_map(char *file)
{
	int		fd;
	t_map	*map;
	char	*line;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror_exit(file);
	line = get_next_line(fd);
	map->w = measure_width(map, line, file);
	while (line)
	{
		map->h++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}
