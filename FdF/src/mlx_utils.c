/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:50:48 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/26 15:50:48 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	fdf_reset_var(t_var *var)
{
	var->zoom = ft_max((WIN_W / var->map->w / 2), (WIN_H / var->map->h / 2));
	var->shift_x = WIN_W / 2;
	var->shift_y = (WIN_H - var->map->h * var->zoom) / 2;
	var->iso = 1;
	var->flat = 1;
	var->rot_x = 0;
	var->rot_y = 0;
	var->rot_z = 0;
}

int	fdf_initialize_var(t_var *var, t_map *map)
{
	var->map = map;
	var->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!var->img)
		return (1);
	fdf_reset_var(var);
	return (0);
}

void	fdf_initialize_mlx(t_var *var)
{
	var->mlx = mlx_init();
	var->img->img = mlx_new_image(var->mlx, WIN_W, WIN_H);
	var->img->addr = mlx_get_data_addr(var->img->img, \
					&var->img->bpp, &var->img->sz_l, &var->img->endian);
	var->win = mlx_new_window(var->mlx, WIN_W, WIN_H, "FdF");
}
/* ******NOT sure if should apply the same rule for shift_x******
[fdf_reset_var]
shift_x:
	centers the map horizontally within the window
shift_y:
	vertically, taking zooming into consideration
var->iso:
	isometric projection mode
	條坐標軸的投影縮放比例相同，並且任意兩條坐標軸投影之間的角度都是120度。
var->flat:
	flat shading mode, 均一著色

[fdf_initialize_mlx]
mlx_init():
	create a connection to the X Window System and returns a pointer to
	an mlx data structure if successful.
mlx_new_image(Window, Width, Height):
	allocates memory for the image data and returns a pointer to an mlx
	image structure
mlx_get_data_addr(Image Pointer, Bits per Pixel, Size of a Line in bytes,\
					Image Data's Endian)
	Endianness: the byte order of the image data stored
mlx_new_window(Window, Width, Height, Ttitle):
	creates a new window
*/