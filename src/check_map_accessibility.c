/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_accessibility.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:14:03 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/13 17:50:28 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	p_not_accessed(char **map)
{
	int (i), j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				break ;
			++j;
		}
		if (map[i][j] == 'P')
			break ;
		++i;
	}
	if (!map[i] || !map[i][j])
		return (0);
	if (i == 0 || j == 0 || !map[i + 1] || !map[i][j + 1])
		return (0);
	if (map[i][j + 1] == '1' && map[i][j - 1] == '1' && map[i + 1][j] == '1'
		&& map[i - 1][j] == '1')
		return (1);
	return (0);
}

int	e_not_accessed(char **map)
{
	int (i), j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				break ;
			++j;
		}
		if (map[i][j] == 'E')
			break ;
		++i;
	}
	if (!map[i] || !map[i][j])
		return (0);
	if (i == 0 || j == 0 || !map[i + 1] || !map[i][j + 1])
		return (0);
	if (map[i][j + 1] == '1' && map[i][j - 1] == '1' && map[i + 1][j] == '1'
		&& map[i - 1][j] == '1')
		return (1);
	return (0);
}

int	is_c_accessed(char **map, int i, int j)
{
	if (!map[i] || !map[i][j])
		return (0);
	if (i == 0 || j == 0 || !map[i + 1] || !map[i][j + 1])
		return (0);
	if (map[i][j + 1] == '1' && map[i][j - 1] == '1' && map[i + 1][j] == '1'
		&& map[i - 1][j] == '1')
		return (0);
	return (1);
}

int	c_not_accessed(char **map)
{
	int (i), j = 0;
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'C')
			{
				if(is_c_accessed(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}