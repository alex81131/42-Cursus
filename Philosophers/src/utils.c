/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:51:50 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/13 18:07:43 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

size_t	get_realtime(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return((t.tv_sec* 1000) + (t.tv_usec / 1000));
}
// tv_sec: The number of seconds since the Epoch (January 1, 1970).
// tv_usec: The number of microseconds (fractions of a second)
// 			since the last whole second.