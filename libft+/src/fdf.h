/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:12:59 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/17 19:12:59 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <limits.h>
# include <math.h>
# include <unistd.h>
# include <sys/stat.h>

// utils.c
void	free_array(char **array);

// error.c
void	err_exit(const char *err, const char *msg);
void	perror_exit(const char *msg);

// handle_args.c
void	ft_tolower_char(char *c);

#endif