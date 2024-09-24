/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:29:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/13 20:27:20 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

__uint32_t	get_time(struct timeval *ref)
{
	struct timeval	current;
	__uint32_t		diff;

	gettimeofday(&current, NULL);
	diff = (current.tv_sec - ref->tv_sec) * 1000;
	diff += (current.tv_usec - ref->tv_usec) / 1000;
	return (diff);
}

void	ft_usleep(__uint32_t time, t_setup *setting)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	(void)setting;
	while (get_time(&current) < time)
	{
		usleep(100);
	}
}
