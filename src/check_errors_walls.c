/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:47:16 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/14 01:35:32 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_not_walls(t_game *game)
{
	int (len), i, j = 0;
	while (game->map[0][j] && game->map[0][j] != '\n')
	{
		if (game->map[0][j] != '1')
			return (free_map(game) ,1);
		j++;
	}
	len = ft_strlen_map(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
			return (free_map(game) ,1);
		if (game->map[i][len - 1] != '1')
			return (free_map(game) ,1);
		i++;
	}
	j = 0;
	while (game->map[i - 1][j] && game->map[i - 1][j] != '\n')
	{
		if (game->map[i - 1][j] != '1')
			return (free_map(game) ,1);
		j++;
	}
	return (0);
}
