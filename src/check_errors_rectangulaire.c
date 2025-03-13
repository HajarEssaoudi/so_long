/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_rectangulaire.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:51:43 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/13 02:28:02 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_not_rectangle(char **map)
{
	int	len;
	int	n_len;
	int	i;

	len = ft_strlen_map(map[0]);
	i = 1;
	n_len = 0;
	while (map[i])
	{
		n_len = ft_strlen_map(map[i]);
		if (n_len != len)
			return (1);
		i++;
	}
	return (0);
}
