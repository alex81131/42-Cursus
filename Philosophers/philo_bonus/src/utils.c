/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:51:50 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/15 20:38:44 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

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

void	check_fed_dead(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	while (!info->fed)
	{

		while (1)
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

void	ph_exit(t_info *info)
{
	int	i;
	int	status;

	i = -1;
	while (++i < info->nb_philo)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			i = -1;
			while (++ < info->nb_philo)
				kill(info->philo[i].pid, SIGTERM);
			break ;
		}
	}
	sem_close(info->show);
	sem_close(info->check);
	sem_close(info->fork);
	sem_unlink("/sem_show");
	sem_unlink("/sem_check");
	sem_unlink("/fork");
	free(info->philo);
}
// waitpid(-1, &status, 0)
// 	normally(0) wait for any child process(-1) to terminate.
// WEXITSTATUS(status) == 1
// 	if exit w/ error