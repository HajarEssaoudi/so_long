/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:02:05 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/18 04:41:24 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_exit_up(t_game *game, int x, int y)
{
	if (game->count_collectibles == 0)
		finish_game_up(game, x, y);
	else
	{
		if (game->map[y - 1][x] == 'C')
			game->count_collectibles--;
		mlx_put_image_to_window(game->mlx, game->window, game->player_img, x
			* XPM_WIDTH, (y - 1) * XPM_HEIGHT);
		mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
			* XPM_WIDTH, y * XPM_HEIGHT);
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
	}
}

void	move_exit_down(t_game *game, int x, int y)
{
	if (game->count_collectibles == 0)
		finish_game_down(game, x, y);
	else
	{
		if (game->map[y - 1][x] == 'C')
			game->count_collectibles--;
		mlx_put_image_to_window(game->mlx, game->window, game->player_img, x
			* XPM_WIDTH, (y + 1) * XPM_HEIGHT);
		mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
			* XPM_WIDTH, y * XPM_HEIGHT);
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
	}
}

void	move_exit_right(t_game *game, int x, int y)
{
	if (game->count_collectibles == 0)
		finish_game_right(game, x, y);
	else
	{
		if (game->map[y - 1][x] == 'C')
			game->count_collectibles--;
		mlx_put_image_to_window(game->mlx, game->window, game->player_img, (x
				+ 1) * XPM_WIDTH, y * XPM_HEIGHT);
		mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
			* XPM_WIDTH, y * XPM_HEIGHT);
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
	}
}

void	move_exit_left(t_game *game, int x, int y)
{
	if (game->count_collectibles == 0)
		finish_game_left(game, x, y);
	else
	{
		if (game->map[y - 1][x] == 'C')
			game->count_collectibles--;
		mlx_put_image_to_window(game->mlx, game->window, game->player_img, (x
				- 1) * XPM_WIDTH, y * XPM_HEIGHT);
		mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
			* XPM_WIDTH, y * XPM_HEIGHT);
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
	}
}
