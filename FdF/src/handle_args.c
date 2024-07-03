/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:14:10 by kyeh              #+#    #+#             */
/*   Updated: 2024/07/03 21:48:57 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_tolower_char(char *c)
{
	*c = ft_tolower(*c);
}

static int	parse_color(t_map *map, char *s)
{
	while (*s && (ft_isdigit(*s) || *s == '-' || *s == '+' || *s == ','))
		s++;
	if (*s && *s == 'x')
	{
		map->iscolor = 1;
		ft_striter(s + 1, ft_tolower_char);
		return (ft_atoi_base(s + 1, LHEX));
	}
	else
		return (WHITE);
	return (0);
}

static void	fill_matrix(t_map *map, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	**array;

	y = -1;
	while (++y < map->h)
	{
		line = get_next_line(fd);
		array = ft_split(line, ' ');
		if (!array)
		{
			free(line);
			fdf_free_map(map);
			err_exit("Error", MAL_ERROR);
		}
		x = -1;
		while (++x < map->w)
		{
			map->z_mt[y][x] = ft_atoi(array[x]);
			map->clrs[y][x] = parse_color(map, array[x]);
		}
		free_array(array);
		free(line);
	}
}

static void	parse_file(t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		fdf_free_map(map);
		perror_exit(file);
	}
	fill_matrix(map, fd);
	close(fd);
}

void	fdf_handle_args(t_map **map, int ac, char **av)
{
	char	*file;
	int		fd;

	if (ac != 2)
		err_exit("Error", "Invalid arguments");
	file = av[1];
	fd = open(file, O_RDONLY);
	if (fd == -1)
		err_exit("Error", "Error opening file.");
	close(fd);
	if (!fdf_extension(file))
		err_exit("Error", "Invalid file extension. Expected a .fdf file.");
	ft_printf("Reading map...\n");
	*map = fdf_initialize_map(file);
	fdf_alloc_map(*map);
	parse_file(*map, file);
	fdf_get_min_max_z(*map);
}
/*
fd = open(file, O_RDONLY); to check if file is existent.
*/