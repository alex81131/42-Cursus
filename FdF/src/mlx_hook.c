/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:38:45 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/26 16:38:45 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_close_win(t_var *var)
{
	fdf_free_all(var);
	exit (EXIT_SUCCESS);
	return (0);
}

int	fdf_key_hook(int keycode, t_var *var)
{
	if (keycode == KEY_ESC)
		fdf_close_win(var);
	if (keycode == KEY_R)
		fdf_reset_var(var);
	if (keycode == KEY_W || keycode == KEY_A \
		keycode == KEY_S || keycode == KEY_D)
		fdf_handle_move(keycode, var);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		fdf_handle_zoom(keycode, var);
	if (keycode == KEY_U || keycode == KEY_J || keycode == KEY_I\
	 || keycode == KEY_K || keycode == KEY_O || keycode == KEY_L)
		fdf_handle_rot(keycode, var);
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		fdf_handle_flattening(keycode, var);
	if (keycode == KEY_P)
	{
		if (var->iso)
			var->iso = 0;
		else
			var->iso = 1;
	}
	fdf_draw(var);
	return (0);
}
// Takes care of key events
// Change KEY_P for KEY_X?