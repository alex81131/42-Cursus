/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:15:36 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/15 20:06:37 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ph_error(void)
{
	write(2, "Error: invalid arguments.\n", 27);
	return (1);
}

static int	create_threads(t_info *info, pthread_t*id)
{
	int	i;

	i = -1;
	while (++i < info->nb_philo)
	{
		if (pthread_create(&id[i], NULL, &routine, &info->philo[i]))
		{
			write(2, "Error: cannot create thread.\n", 29);
			return (1);
		}
		pthread_mutex_lock(&info->check);
		info->philo[i].last_meal = info->t_0;
		pthread_mutex_unlock(&info->check);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info		info;
	pthread_t	*id;

	if ((argc < 5 || argc > 6) || check_arg(argc, argv, &info))
		return (ph_error());
	id = (pthread_t *)malloc(info.nb_philo * sizeof(pthread_t));
	if (!id)
		return (1);
	info.t_0 = get_realtime();
	if (create_threads(&info, id))
	{
		free(info.philo);
		free(id);
		return (1);
	}
	check_fed_dead(&info);
	ph_exit(&info, id);
	return (0);
}
// nb_philo, time_to_die, time_to_eat, time_to_sleep, [max_eat]
// 5 800 200 200 7

// pthread_create: 
// 	thread_id, NULL=default_attributes, function_to_execute, arguments
// The the moment pthread_create() is called, it creates a new thread
// 	that begins executing concurrently with the main thread and other
// 	philosopher threads.
// -> Implement odd-even strategy for preventing deadlock

// The Dining Philosophers problem requires concurrent execution
// 	of multiple philosophers who act independently. In real life,
// 	they might start thinking or eating at different times.
// 	Using threads allows each philosopher to run its own routine simultaneously
// 	(e.g., thinking, eating) without having to wait for others to finish.