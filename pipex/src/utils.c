/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:52:28 by kyeh              #+#    #+#             */
/*   Updated: 2024/06/11 13:38:10 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int in_or_out)
{
	int	i;

	if (in_or_out == 0)
		i = open(file, O_RDONLY, 0777);
	else if (in_or_out == 1)
		i = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (i == -1)
		error_exit("open_file");
	return (i);
}

void	ft_freetab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*ft_getpath(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*ft_pathcmd(char *cmd, char **env)
{
	char	**allpath;
	char	*path;
	char	**s_cmd;
	char	*exe;
	int		i;

	allpath = ft_split(ft_getpath("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	i = -1;
	while (allpath[++i])
	{
		path = ft_strjoin(allpath[i], "/");
		exe = ft_strjoin(path, s_cmd[0]);
		free(path);
		if (access(exe, F_OK | X_OK) == 0)
		{
			ft_freetab(allpath);
			ft_freetab(s_cmd);
			return (exe);
		}
		free(exe);
	}
	ft_freetab(allpath);
	ft_freetab(s_cmd);
	return (NULL);
}
/*
char *envp[] =
{
//the home directory
	"HOME=/home/user",
//the directories to search for executables
	"PATH=/usr/local/bin:/usr/bin:/bin",
	"USER=user",
	"LANG=en_US.UTF-8",
	NULL
};

ft_substr(string, start, length_copied);

PATH environment variable is set as:
	PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin
and we want to break it down as:
	allpath = {"/usr/local/bin", "/usr/bin", "/bin", "/usr/sbin", "/sbin"};
*/