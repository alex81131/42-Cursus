/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:37:44 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/11 13:58:23 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_exit(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	error_exit_ac(const char *message)
{
	ft_putstr((char *)message);
	exit(EXIT_FAILURE);
}
