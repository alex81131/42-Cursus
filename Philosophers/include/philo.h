/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:54:41 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/15 01:15:24 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

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
	size_t			last_meal;
	pthread_mutex_t	fork;
	struct s_philo	*before;
	struct s_philo	*next;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_philo;
	int				max_eat;
	int				fed;
	int				dead;
	size_t			t_0;
	t_philo			*philo;
	pthread_mutex_t	show;
	pthread_mutex_t	check;
}	t_info;

//	utils_lib
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
//	check_arg
int		check_arg(int argc, char **argv, t_info *info);
//	utils
size_t	get_realtime(void);
void	pass_usec(t_info *info, size_t time);
void	check_dead(t_info *info);
void	ph_exit(t_info *info, pthread_t *id);
//	send_message
void	send_message(t_philo *philo, int message);
//	routine
void	*routine(void *arg);

#endif

// pthread_mutex_t:
// 	Variable used to control access to shared resources