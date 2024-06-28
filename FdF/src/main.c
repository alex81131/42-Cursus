/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:11:22 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/28 17:04:31 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;

	map = NULL;
	fdf_handle_args(&map, ac, av);
	mlx_main(map);
	return (0);
}
/*
• The use of the images of the MiniLibX is mandatory:
	var->img->img = mlx_new_image(var->mlx, WIN_W, WIN_H);
Translate your model: shifting the entire model along axes
*/