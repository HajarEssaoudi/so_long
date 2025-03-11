/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:32:09 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/11 18:09:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_name(char *map)
{
	char	*extention;
	extention = ft_strrchr(map, '.');
	if (extention && ft_strcmp(extention, ".ber") == 0)
		return (1);
	return(0);
}

int main(int ac, char **av)
{
	char	*map;
	int		fd;
	map = av[1];
	if (ac != 2)
		print_error(1);
	if(!check_map_name(map))
		print_error(2);
	fd = open(map,  O_RDONLY);
	if(fd == -1)
	{
		ft_putstr_fd("open failed\n", 2);
		exit(1);
	}
	int height = check_map_validity(fd);
	ft_printf("%d\n", height);
	return(0);
}