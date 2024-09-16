/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:51:50 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/16 16:06:03 by kyeh             ###   ########.fr       */
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

void	*check_fed_dead(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	while (1)
	{
		sem_wait(info->check);
		if (get_realtime() - philo->last_meal \
			> (long long)info->time_to_die)
		{
			send_message(philo, MESSAGE_DIE);
			info->dead = 1;
			exit (1);
		}
		sem_post(info->check);
		if (info->dead)
			break ;
		usleep(1000);
		if (info->max_eat > 0 && philo->meals_eaten >= info->max_eat)
			break ;
	}
	return (NULL);
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
			while (++i < info->nb_philo)
				kill(info->philo[i].pid, SIGTERM);
			break ;
		}
	}
	sem_close(info->show);
	sem_close(info->check);
	sem_close(info->fork);
	sem_unlink("/sem_show");
	sem_unlink("/sem_check");
	sem_unlink("/sem_fork");
	free(info->philo);
}

void	ph_sem_clean(void)
{
	sem_unlink("/sem_show");
	sem_unlink("/sem_check");
	sem_unlink("/sem_fork");
}
// sem_unlink:
// 	Remove the semaphore from the system, ensuring that old
// 	semaphores do not interfere with new ones.
// sem_open:
// 	Create new semaphores with the desired initial values.
// sem_close:
// 	Close semaphore descriptors when they are no longer needed in the process.

// waitpid(-1, &status, 0)
// 	normally(0) wait for any child process(-1) to terminate.
// WEXITSTATUS(status) == 1
// 	if exit w/ error