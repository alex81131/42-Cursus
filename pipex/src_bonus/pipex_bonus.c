/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:29:10 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/10 19:06:30 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exe(char *cmd, char **env)
{
	char	**s_cmd;
	char	*pathcmd;

	s_cmd = ft_split(cmd, ' ');
	pathcmd = ft_pathcmd(s_cmd[0], env);
	if (execve(pathcmd, s_cmd, env) == -1)
	{
		perror("pipex: command not found: ");
		ft_putendl_fd(s_cmd[0], 2);
		ft_freetab(s_cmd);
		free(pathcmd);
		exit(EXIT_FAILURE);
	}
}

void	here_doc_input(char **av, int *p_fd)
{
	char	*result;

	close(p_fd[0]);
	while(1)
	{
		result = get_next_line(STDIN_FILENO);
		if (!result)
		{
			perror("Error: Second limiter cannot be found.\n");
			return ;
		}
		if (ft_strncmp(result, av[2], ft_strlen(av[2])) == 0)
		{
			free(result);
			exit(0);
		}
		ft_putstr_fd(result, p_fd[1]);
		free(result);
	}
}

void	here_doc(char **av)
{
	int	p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		error_exit("Error creating pipe");
	pid = fork();
	if (pid == -1)
		error_exit("Error forking process");
	if (pid == 0)
		here_doc_input(av, p_fd);
	else
	{
		close(p_fd[1]);
		if(dup2(p_fd[0], 0) == -1)
			error_exit("dup2-STDIN_FILENO");
		close(p_fd[0]);
		wait(NULL);
	}
}

void	ft_pipe(char *cmd, char **env)
{
	int	p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		error_exit("Error creating pipe");
	pid = fork();
	if (pid == -1)
		error_exit("Error forking process");
	if (pid == 0)
	{
		close(p_fd[0]);
		if(dup2(p_fd[1], 1) == -1)
			error_exit("dup2-STDOUT_FILENO");
		exe(cmd, env);
	}
	else
	{
		close(p_fd[1]);
		if(dup2(p_fd[0], 0) == -1)
			error_exit("dup2-STDIN_FILENO");
		wait(NULL);
		close(p_fd[0]);
	}
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd_in;
	int	fd_out;

	if (ac < 5)
		error_exit("Usage: ./pipex infile cmd1 cmd2 outfile\n");
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (ac < 6)
			error_exit("Usage:  ./pipex here_doc LIMITER cmd cmd1 file\n");
		i = 3;
		fd_out = open_file(av[ac - 1], 2);
		here_doc(av);
	}
	else
	{
		i = 2;
		fd_in = open_file(av[1], 0);
		fd_out = open_file(av[ac - 1], 1);
		dup2(fd_in, 0);
	}
	while (i < ac - 2)
		ft_pipe(av[i++], env);
	dup2(fd_out, 1);
	exe(av[ac - 2], env);
}
/*
Automatic Cleanup: When a child process exits, either by calling exit() or by 
reaching the end of its main() function, the operating system automatically 
releases various resources associated with that process, including its file 
descriptor table.
So, while it's good practice to close file descriptors that are no longer 
needed to avoid potential resource leaks, in this specific scenario, not 
closing p_fd[1] explicitly in the child process is acceptable because it will 
be closed automatically when the child process exits.
*/