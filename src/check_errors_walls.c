/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:47:16 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/13 02:13:19 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_not_walls(char **map)
{
	int (len), i, j = 0;
	while (map[0][j] && map[0][j] != '\n')
	{
		if (map[0][j] != '1')
			return (1);
		j++;
	}
	len = ft_strlen_map(map[0]);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (1);
		if (map[i][len - 1] != '1')
			return (1);
		i++;
	}
	j = 0;
	while (map[i - 1][j] && map[i - 1][j] != '\n')
	{
		if (map[i - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}
