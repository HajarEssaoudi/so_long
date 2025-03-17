/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:01:39 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/17 01:59:33 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int flag)
{
	ft_putstr_fd("ERROR\n", 2);
	if (flag == 1)
		ft_putstr_fd("Invalid arguments. Usage: ./so_long <map.ber>\n", 2);
	if (flag == 2)
		ft_putstr_fd("Invalid map extension. Use a .ber file.\n", 2);
	if (flag == 3)
		ft_putstr_fd("Empty map or contains empty lines. Use a valid map.\n",
			2);
	if (flag == 4)
		ft_putstr_fd("Map is not rectangular. Use a valid map.\n", 2);
	if (flag == 5)
		ft_putstr_fd("Map must be surrounded by walls.\n", 2);
	if (flag == 6)
		ft_putstr_fd("Map must have at least one collectible.\n", 2);
	if (flag == 7)
		ft_putstr_fd("Map must have exactly one player.\n", 2);
	if (flag == 8)
		ft_putstr_fd("Map must have exactly one exit.\n", 2);
	if (flag == 9)
		ft_putstr_fd("Map can only contain:"
			"C (collectible), P (player), E (exit), 1 (wall), 0 (empty).\n", 2);
	if (flag == 10)
		ft_putstr_fd("there is no valid path in the map.\n", 2);
}
