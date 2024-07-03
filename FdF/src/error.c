/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:37:30 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/21 15:37:30 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_exit(const char *err, const char *msg)
{
	ft_printf_fd(STDERR_FILENO, "%s: %s\n", err, msg);
	exit(EXIT_FAILURE);
}

void	perror_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	fdf_extension(char *file)
{
	char	*dot;

	dot = ft_strrchr(file, '.');
	return (dot && ft_strcmp(dot, ".fdf") == 0);
}
