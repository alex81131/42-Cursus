/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:12:53 by kyeh              #+#    #+#             */
/*   Updated: 2024/05/20 12:12:53 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_input_gnl(int fd, char *line)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	if (!line)
		line = ini_strjoin(line);
	while (!ft_strchr(line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		line = ft_realloc_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*ft_get_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line || !line[i])
		return (NULL);
	while (line [i] && line[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line [i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*new_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line[FOPEN_MAX];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line[fd] = ft_input_gnl(fd, line[fd]);
	if (!line[fd])
		return (NULL);e
	next_line = ft_get_line(line[fd]);
	line[fd] = new_line(line[fd]);
	return (next_line);
}
/*
//	cc -Wall -Werror -Wextra get_next_line_bonus.c get_next_line_utils_bonus.c
//	./a.out test.txt small_test.txt
int	main(int ac, char *av[])
{
	(void)ac;
	int	fd;
	int	fd2;
	char	*line;
	char	*line2;

	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	line = get_next_line(fd);
	line2 = get_next_line(fd2);
	while (line && line2)
	{
		printf("%s", line);
		printf("%s", line2);
		free(line);
		free(line2);
		line = get_next_line(fd);
		line2 = get_next_line(fd2);
	}
	free(line);
	free(line2);
	close(fd);
	close(fd2);
	return (0);
}
*/
/*
-D BUFFER_SIZE=n

Only changed:
1. static char	*line[FOPEN_MAX];
2. line[fd]
*/