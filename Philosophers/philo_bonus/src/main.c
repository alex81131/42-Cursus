/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:15:36 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/16 16:06:17 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static int	ph_error(void)
{
	write(2, "Error: invalid arguments.\n", 27);
	return (1);
}

static void	create_children(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->nb_philo)
	{
		info->philo[i].pid = fork();
		if (info->philo[i].pid == -1)
		{
			write(2, "Error: fork failed.\n", 20);
			exit (1);
		}
		if (info->philo[i].pid == 0)
			routine(&info->philo[i]);
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	ph_sem_clean();
	if ((argc < 5 || argc > 6) || check_arg(argc, argv, &info))
		return (ph_error());
	info.t_0 = get_realtime();
	create_children(&info);
	ph_exit(&info);
	return (0);
}
// nb_philo, time_to_die, time_to_eat, time_to_sleep, [max_eat]
// 5 800 200 200 7

// ph_sem_clean:
// 	clean up left-over semaphores due to program termination,
// 	otherwise there would be no forks inside.

// pthread_create: 
// 	thread_id, NULL=default_attributes, function_to_execute, arguments
// The the moment pthread_create() is called, it creates a new thread
// 	that begins executing concurrently with the main thread and other
// 	philosopher threads.
// -> Implement odd-even strategy for preventing deadlock

// The Dining Philosophers problem requires concurrent execution
// 	of multiple philosophers who act independently. In real life,
// 	they might start thinking or eating at different times.
// 	Using threads allows each philosopher to run its own routine simultaneously
// 	(e.g., thinking, eating) without having to wait for others to finish.