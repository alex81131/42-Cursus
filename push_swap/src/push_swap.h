/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:36:43 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/16 11:47:21 by kyeh             ###   ########.fr       */
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
int		ft_push(t_pile *pile, int range, int push);
//Utils
void	ps_error(int *pile);
int		ps_strlen(char **str);
int		ps_atoi(const char *str, int *pile);
void	check_doubles(int *pile, int size);
int		sort_check(int *pile, int size, int order);
//Quicksort utils
void	three_number_case(t_pile *trois);
void	median_sort(int *pile_temp, int size);
int		qs_median(int *pivot, int *pile, int size);
//Quicksort
void	qs_3a(t_pile *pile, int range);
void	qs_3b(t_pile *pile, int range);
int		qs_pile_a(t_pile *pile, int range, int rotation);
int		qs_pile_b(t_pile *pile, int range, int rotation);
//Bonus
void	read_stdin(t_pile *pile);
int		*c_error(char **av);
void	exe_instruction(t_pile *pile, char *instruction);
void	free_error(t_pile *pile, int choix);

#endif