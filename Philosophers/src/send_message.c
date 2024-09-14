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
		return ("has taken a fork\n");
	if (message == MESSAGE_EAT)
		return ("is eating\n");
	if (message == MESSAGE_SLEEP)
		return ("is sleeping\n");
	if (message == MESSAGE_THINK)
		return ("is thinking\n");
	if (message == MESSAGE_DIE)
		return ("died\n");
	return ("Error: not valid msg id.\n");
}

void	send_message(t_philo *philo, int message)
{
	size_t	t;

	t = get_realtime() - philo->info->t_0;
	pthread_mutex_lock(&philo->info->show);
	if (!philo->info->dead && !philo->info->fed)
	{
		printf("%ld ", t);
		printf(" %d ", philo->id);
		printf("%s", choose_message(message));
		printf("\n");
	}
	pthread_mutex_unlock(&philo->info->show);
}
