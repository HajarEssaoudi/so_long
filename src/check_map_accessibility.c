/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_accessibility.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:14:03 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/16 13:22:57 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collect(char **map)
{
	int (i), j = 0, count = 0;
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				++count;
			}
			j++;
		}
		i++;
	}
	return (count);
}

char	**duplicate_map(char **map)
{
	int		rows;
	int		i;
	char	**new_map;

	rows = 0;
	while (map[rows])
		rows++;
	new_map = malloc(sizeof(char *) * (rows + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		new_map[i] = ft_strdup_map(map[i]);
		// if (!new_map[i])
			// free_map(new_map);
		i++;
	}
	new_map[rows] = NULL;
	return (new_map);
}

void	free_map_char(char **map)
{
	int i = 0;

	if (!map)
		return;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}


int	map_not_accessible(t_game *game)
{
	char	**map_dup;
	int		count;
	int		x = 0;
	int		y = 0;
	
	map_dup = duplicate_map(game->map);
	int i = 0, j = 0;
	while (map_dup[i])
	{
		j = 0;
		while (map_dup[i][j])
		{
			if (map_dup[i][j] == 'P')
			{
				x = j;
				y = i;
			}
			j++;
		}
		i++;
	}
	count = 0;
	flood_fill(map_dup, x, y, 'F');
	count = count_collect(map_dup);
	free_map_char(map_dup);
	if (count > 0)
		return (free_map(game), 1);
	else
		return (0);
}
