/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 05:04:46 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/17 02:30:27 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**store_map(t_game *game)
{
	char *(line), **map;
	int (fd), i;
	i = 0;
	map = malloc((game->map_height + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(game->map_name, O_RDONLY);
	if (fd == -1)
		(ft_putstr_fd("open failed\n", 2), free(game), free(map), exit(1));
	while (i < game->map_height)
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

void	free_map(t_game *game)
{
	int	j;

	j = 0;
	while (j < game->map_height)
	{
		free(game->map[j]);
		j++;
	}
	free(game->map);
}

int	check_map_name(int ac, char *map_name)
{
	if (ac != 2)
		return (print_error(1), 0);
	if (!check_map_ext(map_name))
		return (print_error(2), 0);
	return (1);
}

int	check_map_validity(t_game *game)
{
	if (check_empty_map(game) == 1)
		return (print_error(3), 0);
	if (check_not_rectangle(game) == 1)
		return (print_error(4), 0);
	if (check_not_walls(game) == 1)
		return (print_error(5), 0);
	if (c_not_found(game) == 1)
		return (print_error(6), 0);
	if (p_not_found(game) == 1)
		return (print_error(7), 0);
	if (e_not_found(game) == 1)
		return (print_error(8), 0);
	if (not_element(game) == 1)
		return (print_error(9), 0);
	if (map_not_accessible(game) == 1)
		return (print_error(10), 0);
	return (1);
}
