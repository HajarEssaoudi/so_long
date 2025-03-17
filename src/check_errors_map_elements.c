/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_map_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:39:07 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/17 01:57:20 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	c_not_found(t_game *game)
{
	int (i), j;
	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (free_map(game), 1);
}

int	p_not_found(t_game *game)
{
	int (i), j = 0, count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	if (count == 1)
		return (0);
	return (free_map(game), 1);
}

int	e_not_found(t_game *game)
{
	int (i), j = 0, count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	if (count == 1)
		return (0);
	return (free_map(game), 1);
}

int	not_element(t_game *game)
{
	int (i), j = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != 'E' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'P' && game->map[i][j] != '1'
				&& game->map[i][j] != '0' && game->map[i][j] != '\n')
				return (free_map(game), 1);
			j++;
		}
		i++;
	}
	return (0);
}
