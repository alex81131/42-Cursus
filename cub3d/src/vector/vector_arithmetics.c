/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:49:44 by kyeh              #+#    #+#             */
/*   Updated: 2024/10/10 16:13:34 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vec_ini(t_vec *vec, double x, double y)
{
	vec->x = x;
	vec->y = y;
}

void	vec_add(t_vec *vec_1, const t_vec *vec_2)
{
	vec_1->x = vec_1->x + vec_2->x;
	vec_1->y = vec_1->y + vec_2->y;
}

void	vec_min(t_vec *vec_1, const t_vec *vec_2)
{
	vec_1->x = vec_1->x - vec_2->x;
	vec_1->y = vec_1->y - vec_2->y;
}

void	vec_mul(t_vec *vec, double n)
{
	vec->x = vec->x * n;
	vec->y = vec->y * n;
}

double	vec_dot(const t_vec *vec_1, const t_vec *vec_2)
{
	double	res;

	res = (vec_1->x * vec_2->x) + (vec_1->y * vec_2->y);
	return (res);
}
// int	main(void)
// {
// 	t_vec	a;
// 	t_vec	b;

// 	vec_ini(&a, 3, 4);
// 	vec_ini(&b, 1, 2);
// 	printf("vec_1 ini ax: %.2f, ay: %.2f\n", a.x, a.y);
// 	printf("vec_2 ini bx: %.2f, by: %.2f\n", b.x, b.y);
// 	vec_1dd(&a, &b);
// 	printf("vec_1 after adding b ax: %.2f, ay: %.2f\n", a.x, a.y);
// 	vec_min(&a, &b);
// 	printf("vec_1 after minus b ax: %.2f, ay: %.2f\n", a.x, a.y);
// 	vec_mul(&a, 5);
// 	printf("vec_1 after multiply by 5 ax: %.2f, ay: %.2f\n", a.x, a.y);
// 	printf("vec_1 dot vec_2 is %.2f\n", vec_dot(&a, &b));
// 	printf("abs of a is %.2f\n", vec_1bsv(&a));
// 	printf("distance between a and b: %.2f\n", vec_dist(&a, &b));
// 	vec_mirror(&a);
// 	printf("vec_1 mirrored ax: %.2f, ay: %.2f\n", a.x, a.y);
// 	vec_transpose(&a);
// 	printf("vec_1 transposed ax: %.2f, ay: %.2f\n", a.x, a.y);
// 	vec_rotate(&b, 30);
// 	printf("vec_2 rotated by 30 degree bx: %.2f, by: %.2f\n", b.x, b.y);
// 	return (0);
// // }