/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:04:14 by kyeh              #+#    #+#             */
/*   Updated: 2024/07/23 09:04:14 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lonely_command(size_t i, int in_fd)
{
	pid_t	pid;

	if (!is_builtin(sh()->cmd[i][0]))
	{
		pid = fork();
		if (pid == 0)
		{
			if (sh()->redir[i] == '>' || sh()->redir[i] == 'd')
				right_redir(&i);
			else
			{
				redirect(sh()->fd[1], 1);
				ft_cmd(i);
			}
			if (i > 0)
				close(in_fd);
			exit(EXIT_SUCCESS);
		}
	}
	else
		ft_cmd(i);
	return (EXIT_SUCCESS);
}

void	final_redir(size_t i, int in_fd)
{
	pid_t	pid;

	if (sh()->redir[i - 1] == '|')
	{
		pid = fork();
		if (pid == 0)
		{
			redirect(in_fd, STDIN_FILENO);
			if (sh()->redir[i] == '>' || sh()->redir[i] == 'd')
				right_redir(&i);
			else if (sh()->redir[i] == '<' || sh()->redir[i] == 'h')
				left_redir(&i);
			else
			{
				redirect(sh()->fd[1], 1);
				ft_cmd(i);
			}
			close(sh()->fd[1]);
			exit(EXIT_SUCCESS);
		}
	}
	close(in_fd);
}
