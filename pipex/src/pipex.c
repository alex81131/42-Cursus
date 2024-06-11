/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:29:10 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/11 13:38:38 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe(char *cmd, char **env)
{
	char	**s_cmd;
	char	*pathcmd;

	s_cmd = ft_split(cmd, ' ');
	pathcmd = ft_pathcmd(s_cmd[0], env);
	if (execve(pathcmd, s_cmd, env) == -1)
	{
		perror("exe: command not found");
		ft_putendl_fd(s_cmd[0], 2);
		ft_freetab(s_cmd);
		free(pathcmd);
		exit(EXIT_FAILURE);
	}
}

void	child(char **av, int *p_fd, char **env)
{
	int	fd;

	close(p_fd[0]);
	fd = open_file(av[1], 0);
	if (fd == -1)
		error_exit("open_file");
	if (dup2(fd, 0) == -1)
		error_exit("dup2-STDIN_FILENO");
	if (dup2(p_fd[1], 1) == -1)
		error_exit("dup2-STDOUT_FILENO");
	close(fd);
	close(p_fd[1]);
	exe(av[2], env);
}

void	parent(char **av, int *p_fd, char **env)
{
	int	fd;

	close(p_fd[1]);
	fd = open_file(av[4], 1);
	if (fd == -1)
		error_exit("open_file");
	if (dup2(fd, 1) == -1)
		error_exit("dup2-STDOUT_FILENO");
	if (dup2(p_fd[0], 0) == -1)
		error_exit("dup2-STDIN_FILENO");
	close(fd);
	close(p_fd[0]);
	exe(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (ac != 5)
		error_exit_ac("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n");
	if (pipe(p_fd) == -1)
		error_exit("Error creating pipe");
	pid = fork();
	if (pid == -1)
		error_exit("Error forking process");
	else if (pid == 0)
		child(av, p_fd, env);
	else
	{
		parent(av, p_fd, env);
		wait(NULL);
	}
}
/*
ft_putendl_fd = ft_putstr_fd + \n

dup2(fd1, fd2):
It creates a copy of the file descriptor fd1 and assigns that copy to the 
file descriptor fd2.
After the call, any operations performed on fd2 will be directed to the 
same underlying file or device as fd1.
So with dup2, we  redirect the place the functions read and write onto 
the specific fd we want, but the functions don't know that and they still 
think that they read and write on STDIN/OUT_FILENO.

[Analogies for dup2]
dup2(fd, 0)
Analogy:
Imagine you have a hose (standard input, STDIN_FILENO) that is usually 
connected to a water source (like a keyboard or terminal input). 
When you call dup2(fd, 0), you're disconnecting the hose from the usual 
source and connecting it to a different source (the file referred to by fd).
Effect:
Now, when the process "drinks" (reads) from the hose (STDIN_FILENO), 
it gets water (data) from the new source (the file fd).

dup2(p_fd[1], 1)
Analogy:
Imagine you have another hose (standard output, STDOUT_FILENO) that usually 
pours water into a bucket (the terminal or display). When you call 
dup2(p_fd[1], 1), you're redirecting this hose to pour water into a 
different container (the write end of the pipe p_fd[1]).
Effect:
Now, when the process "pours" (writes) water into the hose (STDOUT_FILENO), 
the water goes into the new container (the pipe p_fd[1]).

dup2(p_fd[1], 1) duplicates the file descriptor p_fd[1] onto the standard 
output file descriptor (STDOUT_FILENO): whatever the child process writes 
to its standard output (using functions like printf, puts, write, etc.) 
will actually be written to the write end of the pipe p_fd.

dup2 doesn't do any action. The drinking and pouring process is determined 
by the exe(av[2], env); and  exe(av[3], env); that follow.
*/