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

#include <philo.h>

static void	pick_up_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&philo->fork);
		send_message(philo, MESSAGE_FORK);
		pthread_mutex_lock(&philo->next->fork);
		send_message(philo, MESSAGE_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		send_message(philo, MESSAGE_FORK);
		pthread_mutex_lock(&philo->fork);
		send_message(philo, MESSAGE_FORK);
	}
}

static void	philo_eat(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (info->nb_philo == 1)
	{
		pass_usec(info, info->time_to_die);
		send_message(philo, MESSAGE_DIE);
		pthread_mutex_unlock(&philo->fork);
		info->dead = 1;
		return ;
	}
	pick_up_forks(philo);
	pthread_mutex_lock(&info->check);
	philo->meals_eaten++;
	philo->last_meal = get_realtime();
	send_message(philo, MESSAGE_EAT);
	pthread_mutex_unlock(&info->check);
	pass_usec(info, info->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!info->dead && !info->fed)
	{
		philo_eat(philo);
		send_message(philo, MESSAGE_SLEEP);
		pass_usec(info, info->time_to_sleep);
		send_message(philo, MESSAGE_THINK);
	}
	return (NULL);
}
// philo->id % 2 == 0: usleep(1000)
// 	Stagger the start of philosophers to avoid simultaneous fork grabbing.
// pick_up_forks:
// 	If a philosopher tries to pick up a fork that is already locked
// 	by another philosopher, they must wait.