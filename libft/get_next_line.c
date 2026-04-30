/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:27:14 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/31 10:37:12 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

static char	*_free_buffer_and_return_null(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

static int	read_in_buffer(int fd, char **buffer)
{
	char	*tmp;
	char	*joined;
	ssize_t	bytes_read;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (-1);
	bytes_read = 1;
	while ((bytes_read > 0) && ((!*buffer) || !ft_strchr(*buffer, '\n')))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		tmp[bytes_read] = '\0';
		if (!*buffer)
			*buffer = ft_strdup(tmp);
		else
		{
			joined = ft_strjoin(*buffer, tmp);
			free(*buffer);
			*buffer = joined;
		}
	}
	free(tmp);
	return (bytes_read);
}

static char	*_split_buffer_and_return_line(char **buffer, char **newline_pos)
{
	char	*tmp;
	char	*line;

	line = ft_substr(*buffer, 0, *newline_pos - *buffer + 1);
	if (!line)
		return (_free_buffer_and_return_null(buffer));
	tmp = ft_strdup(*newline_pos + 1);
	if (!tmp)
	{
		free(line);
		return (_free_buffer_and_return_null(buffer));
	}
	free(*buffer);
	*buffer = tmp;
	return (line);
}

static char	*_get_all_from_buffer(char **buffer)
{
	char	*line;

	if (!*buffer || **buffer == '\0')
		return (_free_buffer_and_return_null(buffer));
	line = ft_strdup(*buffer);
	if (!line)
		return (_free_buffer_and_return_null(buffer));
	_free_buffer_and_return_null(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*registry[1024];
	char		*newline_pos;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (_free_buffer_and_return_null(&registry[fd]));
	bytes_read = read_in_buffer(fd, &registry[fd]);
	if (bytes_read < 0 || !registry[fd] || *registry[fd] == '\0')
		return (_free_buffer_and_return_null(&registry[fd]));
	newline_pos = ft_strchr(registry[fd], '\n');
	if (newline_pos)
		return (_split_buffer_and_return_line(&registry[fd], &newline_pos));
	else
		return (_get_all_from_buffer(&registry[fd]));
}
