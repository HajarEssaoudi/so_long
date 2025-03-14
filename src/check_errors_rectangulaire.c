/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_rectangulaire.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:51:43 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/14 01:31:28 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_not_rectangle(t_game *game)
{
	int	len;
	int	n_len;
	int	i;

	len = ft_strlen_map(game->map[0]);
	i = 1;
	n_len = 0;
	while (game->map[i])
	{
		n_len = ft_strlen_map(game->map[i]);
		if (n_len != len)
			return (free_map(game), 1);
		i++;
	}
	return (0);
}
