/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:09:06 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/09 16:26:10 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vec_abs(const t_vec *vec)
{
	double	abs;

	abs = sqrt((vec->x * vec->x) + (vec->y * vec->y));
	return (abs);
}

double	vec_d(const t_vec *vec_1, const t_vec *vec_2)
{
	double	d;
	double	d_x;
	double	d_y;

	d_x = vec_2->x - vec_1->x;
	d_y = vec_2->y - vec_1->y;
	d = sqrt((d_x * d_x) + (d_y * d_y));
	return (d);
}

void	vec_mirror(t_vec *vec)
{
	vec->x = vec->x * -1;
	vec->y = vec->y * -1;
}

void	vec_transpose(t_vec *vec)
{
	double	temp;

	temp = vec->x;
	vec->x = vec->y;
	vec->y = temp;
}

void	vec_rotate(t_vec *vec, double angle)
{
	double	x;
	double	y;
	double	pi;
	double	rad;

	pi = acos(-1);
	rad = angle * pi / 180;
	x = vec->x * cos(rad) - vec->y * sin(rad);
	y = vec->x * sin(rad) + vec->y * cos(rad);
	vec->x = x;
	vec->y = y;
}
