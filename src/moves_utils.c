/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:33:40 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/17 02:45:51 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_game *game)
{
	int (i), j = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	message_success(t_game *game)
{
	ft_printf("                🎉 Congratulations! 🎉\n"
		"      🏆 You've completed the game in %d moves!\n"
		"  🔄 Try to beat your record with fewer moves next time! 💪\n",
		game->move);
}

void	finish_game_one(t_game *game, int x, int y, int flag)
{
	if (flag == 1)
	{
		if (game->map[y - 1][x] == 'E' && game->count_collectibles == 0)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->player_img, x
				* XPM_WIDTH, (y - 1) * XPM_HEIGHT);
			mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
				* XPM_WIDTH, (y) * XPM_HEIGHT);
			message_success(game);
			close_window(game);
		}
	}
	else if (flag == 2)
	{
		if (game->map[y + 1][x] == 'E' && game->count_collectibles == 0)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->player_img, x
				* XPM_WIDTH, (y + 1) * XPM_HEIGHT);
			mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
				* XPM_WIDTH, (y) * XPM_HEIGHT);
			message_success(game);
			close_window(game);
		}
	}
}

void	finish_game_two(t_game *game, int x, int y, int flag)
{
	if (flag == 3)
	{
		if (game->map[y][x - 1] == 'E' && game->count_collectibles == 0)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->player_img,
				(x - 1) * XPM_WIDTH, y * XPM_HEIGHT);
			mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
				* XPM_WIDTH, (y) * XPM_HEIGHT);
			message_success(game);
			close_window(game);
		}
	}
	else if (flag == 4)
	{
		if (game->map[y][x + 1] == 'E' && game->count_collectibles == 0)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->player_img,
				(x + 1) * XPM_WIDTH, y * XPM_HEIGHT);
			mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
				* XPM_WIDTH, (y) * XPM_HEIGHT);
			message_success(game);
			close_window(game);
		}
	}
}
