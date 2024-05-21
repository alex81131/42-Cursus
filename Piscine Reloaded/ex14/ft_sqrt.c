/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:35:43 by kyeh              #+#    #+#             */
/*   Updated: 2024/05/14 15:35:43 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	min;
	long	max;
	long	mid;

	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (nb);
	min = 1;
	max = nb;
	while (min <= max)
	{
		mid = (max + min) / 2;
		if (mid * mid == nb)
			return (mid);
		else if (mid * mid > nb)
			max = mid - 1;
		else
			min = mid + 1;
	}	
	return (0);
}
/*
//integer only stores integer = whole number, integral number
//Using binary search algorithm to avoid potential overtime
//using long instead of int to avoid overflow during calculation
#include <stdio.h>
int	main(void)
{
    int i;

    i = 12645;
	printf("%i", ft_sqrt(i * i));
	return (0);
}
*/
