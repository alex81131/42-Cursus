/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:33:41 by kyeh              #+#    #+#             */
/*   Updated: 2024/05/14 15:33:41 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0 || nb > 12)
		return (0);
	i = 1;
	while (nb > 0)
		i *= nb--;
	return (i);
}
/*
//Automatically includes when nb == 0
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_iterative_factorial(-120));
	printf("%i\n", ft_iterative_factorial(5));
	printf("%i\n", ft_iterative_factorial(12));
	return (0);
}
*/
