/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:14:09 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/18 04:21:00 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_exit_up(t_game *game, int x, int y)
{
	if (game->map[y - 1][x] == 'C')
		game->count_collectibles--;
	mlx_put_image_to_window(game->mlx, game->window, game->player_img,
		x * XPM_WIDTH, (y - 1) * XPM_HEIGHT);
	mlx_put_image_to_window(game->mlx, game->window, game->exit_img,
		x * XPM_WIDTH, y * XPM_HEIGHT);
	game->map[y][x] = 'E';
	game->map[y - 1][x] = 'P';
}

void	handle_exit_down(t_game *game, int x, int y)
{
	if (game->map[y - 1][x] == 'C')
		game->count_collectibles--;
	mlx_put_image_to_window(game->mlx, game->window, game->player_img,
		x * XPM_WIDTH, (y + 1) * XPM_HEIGHT);
	mlx_put_image_to_window(game->mlx, game->window, game->exit_img,
		x * XPM_WIDTH, y * XPM_HEIGHT);
	game->map[y][x] = 'E';
	game->map[y + 1][x] = 'P';
}

void	handle_exit_right(t_game *game, int x, int y)
{
	if (game->map[y - 1][x] == 'C')
		game->count_collectibles--;
	mlx_put_image_to_window(game->mlx, game->window, game->player_img,
		(x + 1) * XPM_WIDTH, y * XPM_HEIGHT);
	mlx_put_image_to_window(game->mlx, game->window, game->exit_img,
		x * XPM_WIDTH, y * XPM_HEIGHT);
	game->map[y][x] = 'E';
	game->map[y][x + 1] = 'P';
}

void	handle_exit_left(t_game *game, int x, int y)
{
	if (game->map[y - 1][x] == 'C')
		game->count_collectibles--;
	mlx_put_image_to_window(game->mlx, game->window, game->player_img,
		(x - 1) * XPM_WIDTH, y * XPM_HEIGHT);
	mlx_put_image_to_window(game->mlx, game->window, game->exit_img,
		x * XPM_WIDTH, y * XPM_HEIGHT);
	game->map[y][x] = 'E';
	game->map[y][x - 1] = 'P';
}
