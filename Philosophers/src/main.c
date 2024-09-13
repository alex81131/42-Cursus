/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:15:36 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/13 18:07:42 by kyeh             ###   ########.fr       */
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
	id = (pthread_t *)malloc(info.nb_philo * sizeof(pthread_t));
	info.t_0 = 
}
// nb_philo, time_to_die, time_to_eat, time_to_sleep, [max_eat]
// 5 800 200 200 7