/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cos_scale.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:28:54 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/09 17:16:12 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vec_cos(t_vec *vec_1, t_vec *vec_2)
{
	double	cos;

	cos = vec_dot(vec_1, vec_2) / (vec_abs(vec_1) * vec_abs(vec_2));
	return (cos);
}

void	vec_copy_scale(t_vec *vec_2, const t_vec *vec_1, double scale)
{
	vec_2->x = vec_1->x;
	vec_2->y = vec_1->y;
	vec_mul(vec_2, scale);
}
