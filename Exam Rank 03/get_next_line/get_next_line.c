#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 12
#endif

int	ft_strlen(char *str)
{
	int	i = 0;

	while(str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, int len)
{
	int	i = 0;

	if (!dest && !src)
		return (NULL);
	if (dest != src)
	{
		while (i < len)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strdup(char *str)
{
	int		len = ft_strlen(str);
	char	*res;

	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, str, len);
	res[len] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, ft_strlen(s1));
	ft_memcpy(res + ft_strlen(s1), s2, ft_strlen(s2));
	res[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (res);
}

char	*ft_strchr(char *str, char c)
{
	while (*str != c)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return (str);
}

char	*ft_substr(char *src, int start, int len)
{
	char	*res;
	int		len_src = ft_strlen(src);
	int		len_res = 0;

	if (!src)
		return (NULL);
	if (start < len_src)
		len_res = len_src - start;
	if (len_res > len)
		len_res = len;
	res = (char *)malloc((len_res + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, src + start, len_res);
	res[len_res] = '\0';
	return (res);
}

char	*return_next_line(char **line)
{
	char	*res;
	char	*next;
	int		i = 0;

	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
	{
		res = ft_substr(*line, 0, i + 1);
		next = ft_strdup(*line + i + 1);
		free(*line);
		*line = next;
		if (!**line)
		{
			free(*line);
			*line = NULL;
		}
		return (res);
	}
	res = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (res);
}

char	*check_and_return(char **line, int n, int fd)
{
	if (n < 0)
		return (NULL);
	if (!n && (!line[fd] || !*line[fd]))
		return (NULL);
	return (return_next_line(&line[fd]));
}

char	*get_next_line(int fd)
{
	char		*buff;
	int			n;
	static char	*line[FOPEN_MAX];
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	n = read(fd, buff, BUFFER_SIZE);
	while (n > 0)
	{
		buff[n] = '\0';
		if (!line[fd])
			line[fd] = ft_strdup("");
		temp = ft_strjoin(line[fd], buff);
		free(line[fd]);
		line[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
		n = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (check_and_return(line, n, fd));
}
