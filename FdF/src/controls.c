/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:00:59 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/24 17:00:59 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_handle_zoom(int keycode, t_var *var)
{
	if (key_code == KEY_DOWN)
	{
		if (var->zoom > 0)
			var->zoom -= ZOOM_SHIFT;
	}
	if (key_code == KEY_UP)
	{
		if (var->zoom < INT_MAX)
			var->zoom += ZOOM_SHIFT;
	}
}

void	fdf_handle_flattening(int keycode, t_var *var)
{
	if (keycode == KEY_PLUS)
	{
		if (var->flat < 10)
			var->flat += 0.1;
	}
	if (keycode == KEY_MINUS)
	{
		if (var->flat > 0)
			var->flat -= 0.1;
	}
}

void	fdf_handle_rot(int keycode, t_var *var)
{
	if (keycode == KEY_U)
		var->rot_x += ROT_SHIFT;
	if (keycode == KEY_J)
		var->rot_x += ROT_SHIFT;
	if (keycode == KEY_I)
		var->rot_x += ROT_SHIFT;
	if (keycode == KEY_K)
		var->rot_x += ROT_SHIFT;
	if (keycode == KEY_O)
		var->rot_x += ROT_SHIFT;
	if (keycode == KEY_L)
		var->rot_x += ROT_SHIFT;
}
