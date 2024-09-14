/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:21:10 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/14 23:41:16 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	check_positive_nb(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '-')
			return (1);
		else if (argv[i][0] == '+')
			j++;
		if (!ft_isdigit(argv[i][j + 1]))
			return (1);
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (1);
	}
	return (0);
}

static int	check_integer(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (*str == '+' && str++)
		len--;
	while (*str && *str == '0' && len--)
		str++;
	if (len > 10)
		return (1);
	else if (len < 10)
		return (0);
	if (ft_strncmp(str, "2147483648", 10) >= 0)
		return (1);
	return (0);
}

static int	check_number(int argc, char **argv)
{
	int	i;

	if (check_positive_nb(argc, argv))
		return (1);
	i = 0;
	while (++i < argc)
		if (check_integer(argv[i]))
			return (1);
	return (0);
}

static void	initialize_info(t_info *info)
{
	int	i;

	info->dead = 0;
	info->fed = 0;
	info->philo = (t_philo *)malloc(info->nb_philo * sizeof(t_philo));
	if (!info->philo)
		return ;
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
			info->philo[i].next = &info->philo[i - 1];
		pthread_mutex_init(&info->philo[i].fork, NULL);
	}
	pthread_mutex_init(&info->show, NULL);
	pthread_mutex_init(&info->check, NULL);
}

int	check_arg(int argc, char **argv, t_info *info)
{
	if (check_number(argc, argv))
		return (1);
	info->nb_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->max_eat = -1;
	if (argc == 6)
		info->max_eat = ft_atoi(argv[5]);
	initialize_info(info);
	return (0);
}
