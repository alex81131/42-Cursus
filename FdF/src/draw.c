/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:56:29 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/24 17:56:29 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_menu(t_var *var)
{
	int		y;
	void	*mlx;
	void	*win;

	mlx = var->mlx;
	win = var->win;
	y = 0;
	mlx_string_put(mlx, win, 15, y += 15, WHITE, "Controls:");
	mlx_string_put(mlx, win, 15, y += 50, WHITE, "Reset: R");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Move: W, A, S, D");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Zoom: Arrows");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Flattening: + / -");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Rotate:");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  x (+ / -): U / J");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  y (+ / -): I / K");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  z (+ / -): O / L");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Toggle Perspective: P");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "(Isometric and Parallel)");
}

static int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static void	initialize_besenham(t_point *start, t_point *end, \
								t_point *delta, t_point *sign)
{
	delta->x = ft_abs(end->x - start->x);
	delta->y = ft_abs(end->y - start->y);
	sign->x = -1;
	sign->y = -1;
	if (start->x < end->x)
		sign->x = 1;
	if (start->y < end->y)
		sign->y = 1;
}

static void	bresenham(t_var *var, t_point start, t_point end)
{
	t_point	cur;
	t_point	sign;
	t_point	d;
	int		error;
	int		k;

	initialize_besenham(&start, &end, &d, &sign);
	error = d.x - d.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		fdf_img_pixel_put(var, cur.x, cur.y, \
							fdf_get_color(cur, start, end, d));
		k = error * 2;
		if (k > -d.y)
		{
			error -= d.y;
			cur.x += sign.x;
		}
		if (k < d.x)
		{
			error += d.x;
			cur.y += sign.y;
		}
	}
}

void	fdf_draw(t_var *var)
{
	int	x;
	int	y;

	ft_bzero(var->img->addr, WIN_H * WIN_W * (var->img->bpp / 8));
	if (var->zoom)
	{
		y = -1;
		while (++y < var->map->h)
		{
			x = -1;
			while (++x < var->map->w)
			{
				if (x < var->map->w - 1)
					bresenham(var, \
						fdf_get_coords(var, fdf_new_point(x, y, var)), \
						fdf_get_coords(var, fdf_new_point(x + 1, y, var)));
				if (y < var->map->h - 1)
					bresenham(var, \
						fdf_get_coords(var, fdf_new_point(x, y, var)), \
						fdf_get_coords(var, fdf_new_point(x, y + 1, var)));
			}
		}
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	draw_menu(var);
}
/*
bresenham:
k = error * 2, error = d.x - d.y
	to avoid dealing with fractional values, making the comparison
	more sensitive, simpler and faster.
	(error is used to determine which makes a more significant move:
	d.x or d.y)
The reason for the conditions k > -d.y and k < d.x, check Wiki:
https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
#Algorithm_for_integer_arithmetic
*/