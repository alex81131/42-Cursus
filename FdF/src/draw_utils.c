/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:39:52 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/26 17:39:52 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_var *var, int *x, int *y, int *z)
{
	int	prev_x;
	int	prev_y;

	if (!var->iso)
		return ;
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

void	fdf_rot_x(t_var *var, int *y, int *z)
{
	float	prev_y;

	prev_y = *y;
	*y = (prev_y * cos(var->rot_x)) + (*z * sin(var->rot_x));
	*z = (-prev_y * sin(var->rot_x)) + (*z * cos(var->rot_x));
}

void	fdf_rot_y(t_var *var, int *x, int *z)
{
	float	prev_x;

	prev_x = *x;
	*x = (*x * cos(var->rot_y)) + (*z * sin(var->rot_y));
	*z = (-prev_x * sin(var->rot_y)) + (*z * cos(var->rot_y));
}

void	fdf_rot_z(t_var *var, int *x, int *y)
{
	float	prev_x;

	prev_x = *x;
	*x = (*x * cos(var->rot_z)) - (*y * sin(var->rot_z));
	*y = (prev_x * sin(var->rot_z)) + (*y * cos(var->rot_z));
}

fdf_img_pixel_put(t_var *var, int x, int y, int color)
{
	int	pixel;

	if (y >=WIN_H || x >= WIN_W || y < 0 || x < 0)
		return ;
	pixel = (y * var->img->sz_l) + (x * (var->img->bpp / 8));
	if (var->img->endian == 1)
	{
		var->img->addr[pixel + 0] = (color >> 24) & 0xFF;
		var->img->addr[pixel + 1] = (color >> 16) & 0xFF;
		var->img->addr[pixel + 2] = (color >> 8) & 0xFF;
		var->img->addr[pixel + 3] = color & 0xFF;
	}
	else if (var->img->endian == 0)
	{
		var->img->addr[pixel + 0] = color & 0xFF;
		var->img->addr[pixel + 1] = (color >> 8) & 0xFF;
		var->img->addr[pixel + 2] = (color >> 16) & 0xFF;
		var->img->addr[pixel + 3] = color >> 24;
	}
}
/*
fdf_img_pixel_put:
	sets the color of a pixel at specific coordinates.

Since mlx_get_data_addr points to the start of the image data buffer,
	var->img->addr is linear array in memory where pixel data for the 
	entire image is stored.

The formula of mlx_get_data_addr,
	pixel = (y * var->img->sz_l) + (x * (var->img->bpp / 8)),
	guarantees that no two distinct pairs of (x, y) coordinates will map 
	to the same pixel value under normal conditions.

sz_l, size of each line (or row) in bytes
bpp/8, size in bytes used to store the color information of each pixel
(indexing generally refers to moving in bytes)
(Moreover:
var->img->bpp / 8, because each color is stored in 8 bits,
	1 byte, 2 digits in hexidecimal.
	1 byte per pixel, one color per pixel)

So with the formula above, we can correctly access the memory we want
	with the correct displacement.
	ie.0x'A'ARRGGBB and not randomly 0xAARRG'G'BB

Endian = 1: (big-endian)
	The color components are written to memory in the order of
	alpha, red, green, blue. (AARRGGBB)
Endian = 0: (little-endian)
	blue, green, red, alpha
*/