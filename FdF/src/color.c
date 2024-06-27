/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:35:04 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/22 11:35:04 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(int start, int end, int current)
{
	double	displacement;
	double	distance;

	displacement = current - start;
	distance = end - start;
	if (!distance)
		return (1.0);
	return (displacement / distance);
}

static int	mix_colors(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int	fdf_get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	r = mix_colors((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, \
															percentage);
	g = mix_colors((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, \
															percentage);
	b = mix_colors(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}

int	fdf_get_z_color(t_var *var, int cur_z)
{
	double	percentage;

	percentage = percent(var->map->min_z, var->map->max_z, cur_z);
	if (percentage < 0.2)
		return (COLOR_1);
	else if (percentage < 0.4)
		return (COLOR_2);
	else if (percentage < 0.6)
		return (COLOR_3);
	else if (percentage < 0.8)
		return (COLOR_4);
	else
		return (COLOR_5);
}
/*
0xAARRGGBB
1. color >> 16 shifts the bits 16 positions to the right
→ 0x0000AARR
2. 0xFF = 0x000000FF = 0000 0000 0000 0000 0000 0000 1111 1111
Hence obviously when doing a bitwise AND operation with 0xFF,
0xFF filters out everything but the lowest 8 bits, 2 digits in hexidecimal,
→ 0xRR

return ((r << 16) | (g << 8) | b);
shift and combine

delta is a structure containing the differences in x and y coordinates 
between the start and end points.

Ensure Smooth Interpolation by choosing the Dominant Direction:
By selecting the direction with the greater difference (either x or y), 
we ensure that the interpolation respects the primary direction of 
the line segment. if there isn't much of a difference, then choosing 
either is good.
*/