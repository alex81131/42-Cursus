/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:15:36 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/12 15:20:54 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ph_error(void)
{
	write(2, "Error! Invalid arguments.\n", 27);
	return (1);
}
int	main(int argc, char **argv)
{
	int			i;
	t_table		tab;
	pthread_t	*id;

	if ((argc < 5 || argc > 6) || check_arg(argc, argv, &tab))
		return (ph_error());
	
}