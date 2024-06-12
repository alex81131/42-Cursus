/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:36:43 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/12 18:21:35 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft+/src/libft.h"
# include <stdlib.h>

typedef struct s_pile
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_pile;

void	push_swap(char **av);
void	ps_error(int *pile);
int		ps_strlen(char **str);
int		ps_atoi(const char *str, int *pile);
void	check_doubles(int *pile, int size);
//Operations
void	swap_a(t_pile *pile, int bonus);
void	swap_b(t_pile *pile, int bonus);
void	swap_s(t_pile *pile, int bonus);
void	rotate_a(t_pile *pile, int bonus);
void	rotate_b(t_pile *pile, int bonus);
void	rotate_r(t_pile *pile, int bonus);
void	reverse_rotate_a(t_pile *pile, int bonus);
void	reverse_rotate_b(t_pile *pile, int bonus);
void	reverse_rotate_r(t_pile *pile, int bonus);
void	push_b(t_pile *pile, int bonus);
void	push_a(t_pile *pile, int bonus);
//Sort
int		sort(t_pile *pile, int size);
int		check_sorted(int *pile, int size, int order);
void	three_number_case_pile_a(t_pile *three);
void	tmp_sort(int *pile_tmp, int size);
//Quicksort
int		qs_pile_a(t_pile *pile, int len, int count_r);
int		qs_pile_b(t_pile *pile, int len, int count_r);
void	qs_3pile_ab(t_pile *pile, int len);
int		sort_3b