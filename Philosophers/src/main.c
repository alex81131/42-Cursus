/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:15:36 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/13 18:21:02 by kyeh             ###   ########.fr       */
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
	info.t_0 = get_realtime();
	i = -1;
	while (++i < info.nb_philo)
	{
		if (pthread_create(&id[i], NULL, &routine, &info.philo[i]))
		{
			write(2, "Error! Cannot create thread.\n", 29);
			free(info.philo);
			free(id);
			return (1);
		}
		pthread_mutex_lock(&info.check);
		info.philo[i].last_meal = info.t_0;
		pthread_mutex_unlock(&info.check);
	}
	check_dead
}
// nb_philo, time_to_die, time_to_eat, time_to_sleep, [max_eat]
// 5 800 200 200 7

pthread_create: 
	(thread_id, NULL=default_attributes, function_to_execute, arguments)