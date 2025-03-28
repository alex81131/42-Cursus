/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:59:12 by kyeh              #+#    #+#             */
/*   Updated: 2024/09/24 10:20:45 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	err(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return (err("error: cd: bad arguments\n"));
	if (chdir(argv[1]) == -1)
		return (err("error: cd: cannot change directory to "), err(argv[1]), err("\n"));
	return (0);
}

int	exe(char **argv, char **env, int i)
{
	int	fd[2];
	int	status;
	int	have_pipe = argv[i] && !strcmp(argv[i], "|");

	if (have_pipe && pipe(fd) == -1)
		return (err("error: fatal\n"));
	int	pid = fork();
	if (!pid)
	{
		argv[i] = NULL;
		if (have_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (err("error: fatal\n"));
		execve(*argv, argv, env);
		return (err("error: cannot execute "), err(*argv), err("\n"));
	}
	waitpid(pid, &status, 0);
	if (have_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (err("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **env)
{
	int	i = 0;
	int	status = 0;

	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(*argv, "cd"))
				status = cd(argv, i);
			else if (i)
				status = exe(argv, env, i);
		}
	}
	return (status);
}
// In exe's child process: argv[i] = 0
//	to replace "|" and ";" with NULL,
//	putting an end for execve, ignoring the rest of the array.

// dup2(fd[1], 1):
//	The child needs an output port to write, which by default is stdout.
//	dup2(fd[1], 1) closes the stdout and redirects the output port to fd[1],
//	so the new output port for the child becomes fd[1].
// dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
//	all in one line is not problematic, because the redirection has been set,
//	the close the pipe will not affect the connection.

// int	have_pipe = argv[i] && !strcmp(argv[i]. "|")
// = int	have_pipe = (argv[i] && !strcmp(argv[i]. "|"))
// 	returns 1 if both arguments are true.

// execve(*pathname, pointer to cmd+arguments, env)

// W = in the wait() family
// WIDEXITED(status):
// 	checks if a child process terminated normally
// WEXITSTATUS(status):
// 	retrieves the exit status of the child process, if WIFEXITED is true.
