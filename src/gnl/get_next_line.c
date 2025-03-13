/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:46:34 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/13 00:32:20 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_remainder(int fd, char *remainder)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin_gnl(remainder, buffer);
		if (!temp)
			return (NULL);
		free(remainder);
		remainder = temp;
	}
	free(buffer);
	return (remainder);
}

static void	free_remainder(char **remainder)
{
	free(*remainder);
	*remainder = NULL;
}

static char	*extract_line(char **remainder)
{
	char	*line;
	char	*newline;
	char	*temp;

	if (!remainder || !*remainder)
		return (NULL);
	newline = ft_strchr_gnl(*remainder, '\n');
	if (newline)
	{
		line = ft_substr_gnl(*remainder, 0, newline - *remainder + 1);
		temp = ft_strdup_gnl(newline + 1);
		if (!line || !temp)
		{
			free_remainder(remainder);
			return (NULL);
		}
		free_remainder(remainder);
		*remainder = temp;
	}
	else
	{
		line = ft_strdup_gnl(*remainder);
		free_remainder(remainder);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*line;

	if (fd < 0)
		return (NULL);
	remainder = read_to_remainder(fd, remainder);
	if (!remainder || !*remainder)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	line = extract_line(&remainder);
	return (line);
}
