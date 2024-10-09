/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:50:41 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/09 17:17:01 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_bool	is_invalid_char(char c)
{
	if (c == '1' || c == '0')
		return (FALSE);
	else if (c == ' ' || c == '\n')
		return (FALSE);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'D')
		return (FALSE);
	return (TRUE);
}

t_parse_status	check_invalid_char(char **map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (is_invalid_char(map[x][y]) == TRUE)
				return (MAP_ERR);
			y++;
		}
		x++;
		y = 0;
	}
	return (MAP_OK);
}

void	cub_fill_whitespace(char **map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == ' ')
				map[x][y] = '1';
			y++;
		}
		y = 0;
		x++;
	}
}

static uint32_t	is_cardinal(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

t_parse_status	find_start(int coordinate[], char **map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (is_cardinal(map[x][y]))
			{
				if (cooridinate[0] != -1 || cooridinate[1] != -1)
					return (MAP_ERR);
				cooridinate[0] = x;
				cooridinate[1] = y;
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (coordinate[0] == -1 && coordinate[1] == -1)
		return (MAP_ERR);
	return (MAP_OK);
}

// static void	print_map(char **map)
// {
// 	int	x = 0;
// 	int	y = 0;

// 	while (map[x])
// 	{
// 		while (map[x][y])
// 		{
// 			ft_putchar_fd(OUT, map[x][y]);
// 			y++;
// 		}
// 		y = 0;
// 		x++;
// 	}
// }