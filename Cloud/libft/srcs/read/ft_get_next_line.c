/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:33:48 by tclaudel          #+#    #+#             */
/*   Updated: 2020/02/17 13:06:18 by tclaudel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif

#include "libft.h"

int			error(char **ptr, size_t *ptret)
{
	ft_strdel(ptr);
	*ptret = 0;
	return (-1);
}

size_t		overflow(char **line, char **str, size_t *size, char *nl_pointer)
{
	size_t line_size;

	if (nl_pointer != NULL)
		line_size = (size_t)(nl_pointer - *str + 1);
	else
		line_size = *size;
	if (line_size == 0)
	{
		free(*str);
		*str = NULL;
		return (0);
	}
	if ((*line = (char *)malloc(line_size + 1)) == NULL)
		return (error(str, size));
	ft_memcpy(*line, *str, line_size);
	if (!(ft_memchr(*line, '\n', line_size)))
		(*line)[line_size] = '\0';
	else
		(*line)[line_size - 1] = '\0';
	*size -= line_size;
	ft_memcpy(*str, *str + line_size, *size);
	if (!(ft_memchr(*str, '\n', line_size)))
		line_size++;
	return ((ssize_t)line_size);
}

ssize_t		get_next_line(int fd, char **line)
{
	static char			*str = NULL;
	static size_t		size = 0;
	ssize_t				ret;
	char				*tmp;
	char				buffer[BUFFER_SIZE];

	if (read(fd, NULL, 0) == -1 || !line)
		return (-1);
	tmp = ft_memchr(str, '\n', size);
	while (tmp == NULL)
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) == 0)
			break ;
		if (!(tmp = (char *)malloc(size + (size_t)ret)))
			return (error(&str, &size));
		ft_memcpy(tmp, str, size);
		ft_memcpy(tmp + size, buffer, (size_t)ret);
		if (str)
			free(str);
		str = tmp;
		tmp = ft_memchr(str + size, '\n', (size_t)ret);
		size += (size_t)ret;
	}
	return (overflow(line, &str, &size, tmp));
}
