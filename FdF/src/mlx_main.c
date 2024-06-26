/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:58:46 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/26 14:58:46 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mlx_main(t_map *map)
{
	t_var	*var;

	ft_printf("Starting MiniLibX... \n");
	var = (t_var)ft_calloc(1, sizeof(t_var));
	if (!var)
		err_exit("Error", MAL_ERROR);
	if (fdf_initialize_var(var, map))
	{
		fdf_free_all(var);
		err_exit("Error", MAL_ERROR);
	}
	fdf_initialize_mlx(var);
	mlx_hook(var->win, 2, 1L << 0, fdf_key_hook, var);
	mlx_hook(var->win, 17, 1L << 17, fdf_close_win, var);
	fdf_draw(var);
	mlx_loop(var->mlx);
	fdf_free_all(var);
	return (EXIT_SUCCESS);
}
/*
mlx_hook(Window, Event Number, Bitmask, Function, Function Parameters);
[Event Number] type of event to listen for
	2: Key press event
	3: Key release event
	4: Mouse button press event
	5: Mouse button release event
	6: Mouse motion event (mouse move)
	17: Window close event (destroy notify)
[Bitmask] Provides additional details about the event. In many cases, 
it directly corresponds to the event type, but it can be more specific 
or be used for more complex event configurations in other systems.
	1L << 0: Key press event
	1L << 1: Key release event
	1L << 2: Mouse button press event
	1L << 3: Mouse button release event
	1L << 6: Mouse motion event
	1L << 17: Window close event
mlx_loop: an infinite loop that waits for and processes events.
*/