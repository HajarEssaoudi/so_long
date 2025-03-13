/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_map_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:39:07 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/13 02:31:20 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	c_not_found(char **map)
{
	int (i), j;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	p_not_found(char **map)
{
	int (i), j = 0, count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	if (count == 1)
		return (0);
	return (1);
}

int	e_not_found(char **map)
{
	int (i), j = 0, count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	if (count == 1)
		return (0);
	return (1);
}

int	not_element(char **map)
{
	int (i), j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'P'
				&& map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
