/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:44:53 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/13 10:33:16 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(int *pile)
{
	free(pile);
	ft_printf("error\n");
	exit(EXIT_FAILURE);
}

int	ps_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ps_atoi(const char *str, int *pile)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ps_error(pile);
		result = result * 10 + str[i++] - '0';
	}
	return (sign * result);
}

void	check_doubles(int *pile, int size)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i < size)
	{
		while (j < size)
			if (pile[i] == pile[j++])
				ps_error(pile);
		i++;
		j = i + 1;
	}
}

int	check_sorted(int *pile, int size, int order)
{
	int	i;

	if (order == 0)
	{
		i = 1;
		while (i < size)
			if (pile[i - 1] > pile[i++])
				return (0);
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
			if (pile[i - 1] < pile[i++])
				return (0);
		return (1);
	}
}
