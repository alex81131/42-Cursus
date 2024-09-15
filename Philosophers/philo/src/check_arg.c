/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:21:10 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/15 19:13:35 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	check_positive(int argc, char **argv)
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

	while (*str == '+' || *str == '0')
		str++;
	len = ft_strlen(str);
	if (len > 10)
		return (1);
	if (len < 10)
		return (0);
	if (ft_strncmp(str, "2147483647", 10) > 0)
		return (1);
	return (0);
}

static int	check_number(int argc, char **argv)
{
	int	i;

	if (check_positive(argc, argv))
		return (1);
	i = 0;
	while (++i < argc)
		if (check_integer(argv[i]))
			return (1);
	return (0);
}

int	check_arg(int argc, char **argv, t_info *info)
{
	if (check_number(argc, argv))
		return (1);
	info->nb_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (info->nb_philo <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (1);
	if (argc == 6)
	{
		info->max_eat = ft_atoi(argv[5]);
		if (info->max_eat < 0)
			return (1);
	}
	else
		info->max_eat = 0;
	initialize_info(info);
	return (0);
}
// 21474836470 can still pass check_integer, so a check after atoi is needed.