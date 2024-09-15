/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:51:50 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/15 19:33:10 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long long	get_realtime(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((long long)(t.tv_sec * 1000 + t.tv_usec / 1000));
}

void	pass_usec(t_info *info, long long time)
{
	long long	t;

	t = get_realtime();
	while (!info->dead)
	{
		if (get_realtime() - t >= time)
			break ;
		usleep(100);
	}
}

static void	check_fed(t_info *info)
{
	int	i;

	if (info->max_eat <= 0)
		return ;
	i = 0;
	while (i < info->nb_philo && info->philo[i].meals_eaten >= info->max_eat)
		i++;
	if (i == info->nb_philo)
		info->fed = 1;
}

void	check_fed_dead(t_info *info)
{
	int	i;

	while (!info->fed)
	{
		i = -1;
		while (!info->dead && ++i < info->nb_philo)
		{
			pthread_mutex_lock(&info->check);
			if (get_realtime() - info->philo[i].last_meal \
				> (long long)info->time_to_die)
			{
				send_message(&info->philo[i], MESSAGE_DIE);
				info->dead = 1;
			}
			pthread_mutex_unlock(&info->check);
			usleep(1000);
		}
		if (info->dead)
			break ;
		check_fed(info);
	}
}

void	ph_exit(t_info *info, pthread_t *id)
{
	int	i;

	i = -1;
	while (++i < info->nb_philo)
		pthread_join(id[i], NULL);
	i = -1;
	while (++i < info->nb_philo)
		pthread_mutex_destroy(&info->philo[i].fork);
	pthread_mutex_destroy(&info->show);
	pthread_mutex_destroy(&info->check);
	free(info->philo);
	free(id);
}
// check_fed_dead:
// 	usleep(1000), increase sleep interval usleep to avoid busy-waiting,
// 	reducing CPU usage.

// Process as the Road:
// 	The process is like the road that provides the structure, direction,
// 	and space for everything to happen. Each process has its own separate road
// 	that is isolated from other roads (other processes),
// 	with its own memory and resources.
// Threads as the Lanes:
// 	The threads are like the lanes on the road. Multiple lanes (threads) can
// 	exist on the same road (process), and they can move independently
// 	but within the same space. They share the road (memory, resources),
// 	but each lane has its own vehicle (execution flow).
// 	If there’s a problem on one lane (like a crash), it can affect the other
// 	lanes if not handled properly (e.g., race conditions, data corruption).

// pthread_join(id[i], *ptr):
// 	ptr points to a place storing the return value of the waited thread id[i]
// 	and releases the resources used by id[i].

// check_fed_dead:
// 	Check if anyone dies and flag fed if everyone's fed.

// tv_sec: The number of seconds since the Epoch (January 1, 1970).
// tv_usec: The number of microseconds (fractions of a second)
// 			since the last whole second.