/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:32:09 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/16 13:25:11 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include <X11/keysym.h>

int	close_window(t_game	*game)
{
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->collectible_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->space_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	free_map(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit (0);
}

int	what_key(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == XK_Escape)
	{
		close_window(game);
		exit(0);
	}
	else if(keycode == XK_Up)
		move_player_up(game);
	else if (keycode == XK_Down)
		move_player_down(game);
	else if (keycode == XK_Left)
		move_player_left(game);
	else if (keycode == XK_Right)
		move_player_right(game);
	return (0);
}


int	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->x = 0;
	game->y = 0;
	game->move = 0;
	if (!game)
		return (1);
	game->map_name = av[1];
	if (!check_map_name(ac, game->map_name))
		(free(game), exit(1));
	game->map_height = count_lines(game);
	game->map = store_map(game);
	game->count_collectibles = count_collect(game->map);
	if (!check_map_validity(game))
		(free(game), exit(1));
	game->map_width = ft_strlen_map(game->map[1]);
	read_xpm(game);
	render_map(game);
	mlx_hook(game->window, 17, 1L>>0, close_window, game);
	mlx_hook(game->window, 2, 1L>>0, what_key, game);
	mlx_loop(game->mlx);
	return (0);
}
