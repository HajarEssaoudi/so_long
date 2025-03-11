/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:09:18 by root              #+#    #+#             */
/*   Updated: 2025/03/11 17:21:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int count_height(int fd)
{
	char    *line;
	int     count;

	count = 0;
	line = get_next_line(fd);
	while(line)
	{
		++count;
		line = get_next_line(fd);
	}
	return (count);
}