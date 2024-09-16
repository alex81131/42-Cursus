/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:15:43 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/14 22:15:43 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	philo_eat(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (info->nb_philo == 1)
	{
		pass_usec(info, info->time_to_die);
		send_message(philo, MESSAGE_DIE);
		info->dead = 1;
		return ;
	}
	sem_wait(info->fork);
	send_message(philo, MESSAGE_FORK);
	sem_wait(info->fork);
	send_message(philo, MESSAGE_FORK);
	sem_wait(info->check);
	philo->meals_eaten++;
	philo->last_meal = get_realtime();
	send_message(philo, MESSAGE_EAT);
	sem_post(info->check);
	pass_usec(info, info->time_to_eat);
	sem_post(info->fork);
	sem_post(info->fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	philo->last_meal = info->t_0;
	pthread_create(&philo->check_dead, NULL, check_fed_dead, (void *)philo);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!info->dead && !info->fed)
	{
		philo_eat(philo);
		if (info->max_eat > 0 && philo->meals_eaten >= info->max_eat)
			break ;
		send_message(philo, MESSAGE_SLEEP);
		pass_usec(info, info->time_to_sleep);
		send_message(philo, MESSAGE_THINK);
	}
	pthread_join(philo->check_dead, NULL);
	exit (0);
}
// routine: creating a thread to separately monitor the philosopher's status.
// 1. If you try to check for death within the main thread (where the
// 	philosopher is eating, sleeping, etc.), you'd risk blocking that thread
// 	during these actions. By using a separate thread, you can constantly
// 	check if the philosopher has died without interfering with their
// 	main actions.
// 2. This avoids the need to manually check for death after every action like
// 	eating or sleeping in the main loop, which could miss death events
// 	if the philosopher is engaged in other activities.