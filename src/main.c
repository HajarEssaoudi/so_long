/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:32:09 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/13 02:08:39 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*map_name;
	char	**map;

	map_name = av[1];
	map = store_map(map_name);
	if (!check_map_validity(ac, map_name, map))
		exit(1);
	return (0);
}
