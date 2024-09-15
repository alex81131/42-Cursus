/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:51:15 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/14 21:51:15 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static char	*choose_message(int message)
{
	if (message == MESSAGE_FORK)
		return ("has taken a fork");
	if (message == MESSAGE_EAT)
		return ("is eating");
	if (message == MESSAGE_SLEEP)
		return ("is sleeping");
	if (message == MESSAGE_THINK)
		return ("is thinking");
	if (message == MESSAGE_DIE)
		return ("died");
	return ("Error: not valid msg id.");
}

void	send_message(t_philo *philo, int message)
{
	long long	t;

	t = get_realtime() - philo->info->t_0;
	pthread_mutex_lock(&philo->info->show);
	if (!philo->info->dead && !philo->info->fed)
		printf("%lld %d %s\n", t, philo->id, choose_message(message));
	pthread_mutex_unlock(&philo->info->show);
}
