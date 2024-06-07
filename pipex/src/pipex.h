/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:47:59 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/07 19:35:59 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft+/src/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>

void	error_exit(const char *message);
//Handle error
int		open_file(char *file, int in_or_out);
void	ft_freetab(char **tab);
char	*ft_getpath(char *name, char **env);
//Get desired path from the environment array
char	*ft_pathcmd(char *cmd, char **env);
//pathcmd = path/cmd and check which path cmd is in

#endif