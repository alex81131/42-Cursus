/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:54:41 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/16 15:49:19 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

enum e_msg
{
	MESSAGE_FORK = 0,
	MESSAGE_EAT,
	MESSAGE_SLEEP,
	MESSAGE_THINK,
	MESSAGE_DIE
};

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal;
	struct s_philo	*before;
	struct s_philo	*next;
	struct s_info	*info;
	pid_t			pid;
	pthread_t		check_dead;
}	t_philo;

typedef struct s_info
{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_philo;
	int			max_eat;
	int			fed;
	int			dead;
	long long	t_0;
	t_philo		*philo;
	sem_t		*show;
	sem_t		*check;
	sem_t		*fork;
}	t_info;

//	utils_lib
int			ft_isdigit(int c);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
//	check_arg and initialize
int			check_arg(int argc, char **argv, t_info *info);
int			initialize_info(t_info *info);
//	utils
long long	get_realtime(void);
void		pass_usec(t_info *info, long long time);
void		*check_fed_dead(void *arg);
void		ph_exit(t_info *info);
void		ph_sem_clean(void);
//	send_message
void		send_message(t_philo *philo, int message);
//	routine
void		*routine(void *arg);

#endif
// semaphores are more flexible
// 	and deal not only with threads but also processes.