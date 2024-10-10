/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:47:27 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/10 16:04:32 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_vec
{
	double	x;
	double	y;
	int		door;
}	t_vec;

void	vec_ini(t_vec *vec, double x, double y);
void	vec_add(t_vec *vec_1, const t_vec *vec_2);
void	vec_min(t_vec *vec_1, const t_vec *vec_2);
void	vec_mul(t_vec *vec, double scalar);
double	vec_dot(const t_vec *vec_1, const t_vec *vec_2);
double	vec_abs(const t_vec *vec);
double	vec_d(const t_vec *vec_1, const t_vec *vec_2);
void	vec_mirror(t_vec *vec);
void	vec_transpose(t_vec *vec);
void	vec_rotate(t_vec *vec, double angle);
double	vec_cos(t_vec *vec_1, t_vec *vec_2);
void	vec_copy_scale(t_vec *vec_2, const t_vec *vec_1, double scale);

#endif