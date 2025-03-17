/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:09:18 by root              #+#    #+#             */
/*   Updated: 2025/03/17 01:53:45 by hes-saou         ###   ########.fr       */
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

char	*ft_strdup_map(char *s)
{
	char	*ss;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[len] && s[i] != '\n')
		len++;
	ss = (char *)malloc(len + 1);
	if (!ss)
		return (NULL);
	while (i < len)
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
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

void	flood_fill(char **tab, int x, int y, char to_fill)
{
	if (tab[y][x] == '1' || tab[y][x] == 'V' || tab[y][x] == 'F')
		return ;
	if (tab[y][x] == 'E')
	{
		tab[y][x] = 'V';
	}
	else
		tab[y][x] = 'F';
	flood_fill(tab, (x - 1), y, to_fill);
	flood_fill(tab, (x + 1), y, to_fill);
	flood_fill(tab, x, (y - 1), to_fill);
	flood_fill(tab, x, (y + 1), to_fill);
}
