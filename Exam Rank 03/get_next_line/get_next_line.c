/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:38:15 by kyeh              #+#    #+#             */
/*   Updated: 2024/07/03 18:25:45 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 12
#endif

size_t	ft_strlen(const char *str)
{
	size_t	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while ((char)c != *str)
	{
		if (!*str)
			return (0);
		str++;
	}
	return ((char *)str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i = 0;

	if (!dest && !src)
		return (NULL);
	if (dest != src)
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	return (dest);
}

char	*ft_strdup(const char *str)
{
	size_t	len = ft_strlen(str);
	char	*s;

	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	ft_memcpy(s, str, len);
	s[len] = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_s = ft_strlen(s);
	size_t	len_str = 0;

	if (!s)
		return (NULL);
	if (start < len_s)
		len_str = len_s - start;
	if (len_str > len)
		len_str = len;
	str = (char *)malloc((len_str + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len_str);
	str[len_str] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i = 0;
	size_t	j = 0;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

static char	*return_next_line(char **s)
{
	char	*out;
	char	*tmp;
	size_t	len = 0;

	out = NULL;
	while ((*s)[len] != '\n' && (*s)[len])
		len++;
	if ((*s)[len] == '\n')
	{
		out = ft_substr(*s, 0, len + 1);
		tmp = ft_strdup(*s + len + 1);
		free(*s);
		*s = tmp;
		if (!**s)
		{
			free(*s);
			*s = NULL;
		}
		return (out);
	}
	out = ft_strdup(*s);
	free(*s);
	*s = NULL;
	return (out);
}

static char	*check_and_return(char **s, ssize_t n, int fd)
{
	if (n < 0)
		return (NULL);
	if (!n && (!s[fd] || !*s[fd]))
		return (NULL);
	return (return_next_line(&s[fd]));
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*buf;
	static char	*s[FOPEN_MAX];
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup("");
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
		n = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (check_and_return(s, n, fd));
}
/*
//	./a.out test.txt
int	main(int ac, char *av[])
{
	(void)ac;
	int	fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
*/
/*
In check_and_return:
	The condition (!s[fd] || !*s[fd]) checks if the buffer for the given
	file descriptor fd is NULL or empty.

In return_next_line:
	out = ft_substr(*s, 0, len + 1);
	tmp = ft_strdup(*s + len + 1);

	*s			*s+len
	0	1	2	\n		3			len = 3
						tmp

The +1 in ft_substr is to include the \n
(len + 1 is the total length to be copied);
the +1 in ft_strdup is to start after the \n
(len + 1 is the starting point after \n).

stdlib: free, malloc
fcntl: open
stdio; printf, FOPEN_MAX
unistd: read, close
*/