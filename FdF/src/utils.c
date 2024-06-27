/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:53:01 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/21 14:53:01 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	fdf_free_var(t_var *var)
{
	fdf_free_map(var->map);
	if (var->img)
		free(var->img);
	free(var);
}

void	fdf_free_all(t_var *var)
{
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_image(var->mlx, var->img->img);
	fdf_free_var(var);
}

t_point	fdf_new_point(int x, int y, t_var *var)
{
	t_point	out;

	out.x = x;
	out.y = y;
	out.z = var->map->z_mt[y][x];
	if (var->map->iscolor)
		out.color = var->map->clrs[y][x];
	else
		out.color = fdf_get_z_color(var, out.z);
	return (out);
}

t_point	fdf_get_coords(t_var *var, t_point point)
{
	point.x *= var->zoom;
	point.y *= var->zoom;
	point.z *= (var->zoom / 10) * var->flat;
	fdf_rot_x(var, &point.y, &point.z);
	fdf_rot_y(var, &point.x, &point.z);
	fdf_rot_z(var, &point.x, &point.y);
	isometric(var, &point.x, &point.y, point.z);
	point.x += var->shift_x;
	point.y += var->shift_y;
	return (point);
}
