/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:34:12 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/14 01:58:57 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "/home/hes-saou/minilibx-linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef GAME_NAME
#  define GAME_NAME "so_long"
# endif

# ifndef XPM_WIDTH
#  define XPM_WIDTH 64
# endif

# ifndef XPM_HEIGHT
#  define XPM_HEIGHT 64
# endif

typedef struct s_game
{
	char	*map_name;
	char	**map;
	void	*mlx;
	void	*window;
	int		map_height;
	int		map_width;
	void	*collectible_img;
	void	*player_img;
	void	*exit_img;
	void	*wall_img;
	void	*space_img;
}			t_game;

// utils functions
char		*get_next_line(int fd);
size_t		ft_strlen_map(const char *s);
void		free_map(t_game *game);
// error functions
void		print_error(int flag);
// check map
int			check_map_name(int ac, char *map_name);
int			check_map_ext(char *map_name);
int			count_lines(t_game *game);
char		**store_map(t_game *game);
int			check_empty_map(t_game *game);
int			check_not_rectangle(t_game *game);
int			check_not_walls(t_game *game);
int			c_not_found(t_game *game);
int			p_not_found(t_game *game);
int			e_not_found(t_game *game);
int			not_element(t_game *game);
// int			p_not_accessed(char **map);
// int			e_not_accessed(char **map);
// int			c_not_accessed(char **map);
int			check_map_validity(t_game *game);
// render map
void		render_map(t_game *game);
#endif