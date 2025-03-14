/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:09:18 by root              #+#    #+#             */
/*   Updated: 2025/03/14 01:14:02 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_map(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	count_lines(t_game *game)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	fd = open(game->map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open failed\n", 2);
		(free(game), exit(1));
	}
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
