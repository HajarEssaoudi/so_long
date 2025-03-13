/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:34:12 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/13 02:07:08 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "/usr/include/minilibx-linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

// utils functions
char	*get_next_line(int fd);
size_t	ft_strlen_map(const char *s);
// error functions
void	print_error(int flag);
// check map
int		check_map_name(char *map);
int		count_lines(char *map);
char	**store_map(char *map_name);
int		check_empty_map(char **map);
int		check_not_rectangle(char **map);
int		check_not_walls(char **map);
int		c_not_found(char **map);
int		p_not_found(char **map);
int		e_not_found(char **map);
int		not_element(char **map);
int		p_not_accessed(char **map);
int		e_not_accessed(char **map);
int		check_map_validity(int ac, char *map_name, char **map);
#endif