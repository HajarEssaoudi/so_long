/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:38:49 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/18 04:47:06 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	message_success(t_game *game)
{
	ft_printf("                🎉 Congratulations! 🎉\n"
		"      🏆 You've completed the game in %d moves!\n"
		"  🔄 Try to beat your record with fewer moves next time! 💪\n",
		game->move);
}

void	finish_game_up(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->player_img, x
		* XPM_WIDTH, (y - 1) * XPM_HEIGHT);
	mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
		* XPM_WIDTH, (y) * XPM_HEIGHT);
	message_success(game);
	close_window(game);
}

void	finish_game_down(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->player_img, x
		* XPM_WIDTH, (y + 1) * XPM_HEIGHT);
	mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
		* XPM_WIDTH, (y) * XPM_HEIGHT);
	message_success(game);
	close_window(game);
}

void	finish_game_right(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->player_img,
		(x + 1) * XPM_WIDTH, y * XPM_HEIGHT);
	mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
		* XPM_WIDTH, (y) * XPM_HEIGHT);
	message_success(game);
	close_window(game);
}

void	finish_game_left(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->player_img,
		(x - 1) * XPM_WIDTH, y * XPM_HEIGHT);
	mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
		* XPM_WIDTH, (y) * XPM_HEIGHT);
	message_success(game);
	close_window(game);
}
