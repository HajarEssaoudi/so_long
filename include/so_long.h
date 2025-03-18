/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:34:12 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/18 03:36:35 by hes-saou         ###   ########.fr       */
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
	int		x;
	int		y;
	int		x_exit;
	int		y_exit;
	int		move;
	int		count_collectibles;
	void	*collectible_img;
	void	*player_img;
	void	*exit_img;
	void	*wall_img;
	void	*space_img;
}			t_game;

// utils functions
char		*get_next_line(int fd);
size_t		ft_strlen_map(const char *s);
char		*ft_strdup_map(char *s);
void		free_map(t_game *game);
void		flood_fill(char **tab, int x, int y, char to_fill);
int			count_collect(char **map);
void		player_position(t_game *game);
void		exit_position(t_game *game);
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
int			map_not_accessible(t_game *game);
int			check_map_validity(t_game *game);
// render map
void		read_xpm(t_game *game);
void		render_map(t_game *game);
// moves
void		handle_exit_up(t_game *game, int x, int y);
void		handle_exit_down(t_game *game, int x, int y);
void		handle_exit_right(t_game *game, int x, int y);
void		handle_exit_left(t_game *game, int x, int y);
void		move_exit_up(t_game *game, int x, int y);
void		move_exit_down(t_game *game, int x, int y);
void		move_exit_left(t_game *game, int x, int y);
void		move_exit_right(t_game *game, int x, int y);
void		finish_game_up(t_game *game, int x, int y);
void		finish_game_down(t_game *game, int x, int y);
void		finish_game_right(t_game *game, int x, int y);
void		finish_game_left(t_game *game, int x, int y);
void		move_player_up(t_game *game);
void		move_player_down(t_game *game);
void		move_player_left(t_game *game);
void		move_player_right(t_game *game);
int			close_window(t_game *game);
#endif