/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:34:12 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/11 17:23:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG
// # include "/usr/include/minilibx-linux/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

//error functions
void	print_error(int flag);
//check map
int count_height(int fd);
int check_map_validity(int fd);
#endif