/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 05:04:46 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/13 02:06:02 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**store_map(char *map_name)
{
	char *(line), **map;
	int (lines), fd, i;
	i = 0;
	lines = count_lines(map_name);
	map = malloc((lines + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		(ft_putstr_fd("open failed\n", 2), exit(1));
	while (i < lines)
	{
		line = get_next_line(fd);
		if (line)
		{
			map[i] = line;
		}
		else
			map[i] = NULL;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	free_map(char **map, char *map_name)
{
	int	lines;
	int	j;

	lines = 0;
	j = 0;
	lines = count_lines(map_name);
	while (j < lines)
	{
		free(map[j]);
		j++;
	}
	free(map);
}

int	check_map_validity(int ac, char *map_name, char **map)
{
	if (ac != 2)
		return (print_error(1), 0);
	if (!check_map_name(map_name))
		return (print_error(2), 0);
	if (check_empty_map(map) == 1)
		return (print_error(3), 0);
	if (check_not_rectangle(map) == 1)
		return (print_error(4), 0);
	if (check_not_walls(map) == 1)
		return (print_error(5), 0);
	if (c_not_found(map) == 1)
		return (print_error(6), 0);
	if (p_not_found(map) == 1)
		return (print_error(7), 0);
	if (e_not_found(map) == 1)
		return (print_error(8), 0);
	if (not_element(map) == 1)
		return (print_error(9), 0);
	if (p_not_accessed(map) == 1)
		return (print_error(10), 0);
	if (e_not_accessed(map) == 1)
		return (print_error(11), 0);
	free_map(map, map_name);
	return (1);
}
