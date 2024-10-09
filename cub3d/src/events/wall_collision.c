/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:45:58 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/09 17:53:06 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_check(t_vec *step, t_data *data, int add_or_min)
{
	t_vec	pos_temp;

	pos_temp = data->ava_pos;
	if (add_or_min == 1)
		vec_min(&pos_temp, step);
	else
		vec_add(&pos_temp, step);
	if (data->map[(int)floor(pos_temp.x)][(int)floor(pos_temp.y)] == '1')
		return ;
	if (data->map[(int)floor(pos_temp.x)][(int)floor(pos_temp.y)] == 'D')
		return ;
	if (add_or_min == 1)
		vec_min(&data->ava_pos, step);
	else
		vec_add(&data->ava_pos, step);
	return ;
}
