/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:13:17 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/15 20:06:56 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	initialize_philo(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->nb_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].info = info;
		info->philo[i].meals_eaten = 0;
		if (i + 1 == info->nb_philo)
			info->philo[i].next = &info->philo[0];
		else
			info->philo[i].next = &info->philo[i + 1];
		if (i == 0)
			info->philo[i].before = &info->philo[info->nb_philo - 1];
		else
			info->philo[i].before = &info->philo[i - 1];
		pthread_mutex_init(&info->philo[i].fork, NULL);
	}
}

int	initialize_info(t_info *info)
{
	info->dead = 0;
	info->fed = 0;
	info->philo = (t_philo *)malloc(info->nb_philo * sizeof(t_philo));
	if (!info->philo)
		return (1);
	initialize_philo(info);
	pthread_mutex_init(&info->show, NULL);
	pthread_mutex_init(&info->check, NULL);
	return (0);
}
