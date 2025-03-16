/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_emptiness.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:05:24 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/16 13:21:00 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_ext(char *map)
{
	char	*extention;
	char	*name;

	extention = ft_strrchr(map, '.');
	name = ft_strchr(map, '/');
	if (extention && ft_strcmp(extention, ".ber") == 0)
	{
		if (!name || name + 1 == extention)
			return (0);
		return (1);
	}
	return (0);
}

static int	is_line_empty(char *line)
{
	if (line == NULL)
		return (1);
	while (*line)
	{
		if (!ft_isspace((unsigned char)*line))
			return (0);
		line++;
	}
	return (1);
}

static int	check_last_line(char **map)
{
	int(i), last_index;
	i = 0;
	while (map[i])
		i++;
	last_index = ft_strlen(map[i - 1]) - 1;
	if (i > 0 && map[i - 1][0] && map[i - 1][last_index] == '\n')
		return (1);
	return (0);
}

int	check_empty_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map == NULL || game->map[0] == NULL)
		return (free_map(game), 1);
	while (game->map[i])
	{
		if (is_line_empty(game->map[i]) == 1)
			return (free_map(game), 1);
		i++;
	}
	if (check_last_line(game->map) == 1)
		return (free_map(game), 1);
	return (0);
}
