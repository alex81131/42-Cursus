/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:29:10 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/11 18:12:34 by kyeh             ###   ########.fr       */
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
		perror("exe: command not found");
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
	while (1)
	{
		result = get_next_line(STDIN_FILENO);
		if (!result)
		{
			perror("Error: Second limiter cannot be found.\n");
			close(p_fd[1]);
			return ;
		}
		printf("Read line: %s", result);
		if (ft_strncmp(result, av[2], ft_strlen(av[2])) == 0)
		{
			free(result);
			close(p_fd[1]);
			exit(0);
		}
		ft_putstr_fd(result, p_fd[1]);
		free(result);
	}
}

void	here_doc(char **av)
{
	int		p_fd[2];
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
		if (dup2(p_fd[0], 0) == -1)
			error_exit("dup2-STDIN_FILENO");
		close(p_fd[0]);
		wait(NULL);
	}
}

void	ft_pipe(char *cmd, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		error_exit("Error creating pipe");
	pid = fork();
	if (pid == -1)
		error_exit("Error forking process");
	if (pid == 0)
	{
		close(p_fd[0]);
		if (dup2(p_fd[1], 1) == -1)
			error_exit("dup2-STDOUT_FILENO");
		close(p_fd[1]);
		exe(cmd, env);
	}
	else
	{
		close(p_fd[1]);
		if (dup2(p_fd[0], 0) == -1)
			error_exit("dup2-STDIN_FILENO");
		close(p_fd[0]);
		wait(NULL);
	}
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd_in;
	int	fd_out;

	if (ac < 5)
		error_exit_ac("Usage: ./pipex infile \"cmd1\" ... \"cmdn\" outfile\n");
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (ac < 6)
			error_exit_ac("Usage: ./pipex here_doc LIMITER \"cmd\" \"cmd1\" file\n");
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
Usage1: ./pipex file1 cmd1 cmd2... cmdn file2
= < file1 cmd1 | cmd2 | ... | cmdn > file2
Usage2: ./pipex here_doc LIMITER cmd cmd1 file
= cmd << LIMITER | cmd1 >> file

//word count of lines containing "important
./pipex file0 "cat" "grep pattern" "wc -w" file1
< file0 cat | grep pattern | wc -w > file2

//count of unique lines containing "pattern" in file0, sorted alphabetically
./pipex file0 "grep pattern" "sort" "uniq -c" file1
< file0 grep pattern | sort | uniq -c > file2

//in reverse alphabetical order
./pipex file0 "grep -i pattern" "sort -r" "uniq -c" file1
< file0 grep -i pattern | sort -r | uniq -c > file2

//Command Substitution
./pipex file0 "grep $(echo pattern)" "sort" "uniq -c" file1
< file0 grep $(echo pattern) | sort | uniq -c > file2

//Here Document with Command Substitution
./pipex here_doc LIMITER "grep $(echo important)" "wc -w" file1
grep $(echo important) << LIMITER | wc -w >> file2

//Here Document with Multiple Commands
./pipex here_doc LIMITER "grep pattern" "sort" "uniq -c" file1
grep pattern << LIMITER | sort | uniq -c > file2

//Here Document with Arguments(case-insensitive)
./pipex here_doc LIMITER "grep -i pattern" "sort" "uniq -c" file1
grep -i pattern << LIMITER | sort | uniq -c >> file2

//Here Document with Command Substitution
./pipex here_doc LIMITER "grep $(echo pattern)" "sort -r" "uniq -c" file1
grep $(echo pattern) << LIMITER | sort -r | uniq -c > file2

//Invalid infile
./pipex nonexistent_file "ls -l" "wc -l" outfile


dup2(fd1, fd2):
It creates a copy of the file descriptor fd1 and assigns that copy to the 
file descriptor fd2.
After the call, any operations performed on fd2 will be directed to the 
same underlying file or device as fd1.
So with dup2, we  redirect the place the functions read and write onto 
the specific fd we want, but the functions don't know that and they still 
think that they read and write on STDIN/OUT_FILENO.

[When should I close the p_fd]
After creating the pipe and using dup2 to redirect STDIN_FILENO and 
STDOUT_FILENO to the pipe's file descriptors, you can safely close the 
original pipe file descriptors. The processes will continue to use 
STDIN_FILENO and STDOUT_FILENO, which are now internally connected 
to the pipe.

[Close p_fd[1] or not in the here_doc_input?]
Automatic Cleanup: When a child process exits, either by calling exit() or by 
reaching the end of its main() function, the operating system automatically 
releases various resources associated with that process, including its file 
descriptor table.
While the system might eventually close unused pipe ends, explicitly closing 
the write end (p_fd[1]) in the here_doc_input function offers several benefits 
for clarity, signaling, and resource management. It's generally considered good 
practice in most pipe-related programming.

In here_doc_input, it's not necessary to modify here_doc_input to explicitly 
ensure nothing is stored in p_fd[1] when the second limiter is not found. 
Here's why:
1. Automatic Cleanup: As the provided comment in your code mentions, when a 
child process exits (either by calling exit or reaching the end of its main 
function), the operating system automatically cleans up resources associated 
with that process, including its file descriptor table.
2. Child Process Exits: In your here_doc_input function, when the second 
limiter is not found:
2-1. An error message is printed.
2-2. close(p_fd[1]); closes the write end of the pipe.
2-3. return (1); exits the child process.
This sequence of events satisfies the conditions for automatic cleanup. 
When the child process exits, the system will automatically close p_fd[1], 
ensuring no further data can be written to it.
*/