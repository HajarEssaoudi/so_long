/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:58:41 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/18 04:21:59 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_up(t_game *game)
{
	int (x), y = game->y;
	x = game->x;
	if (y > 0)
	{
		if (game->map[y - 1][x] != '1')
		{
			if (game->map[y - 1][x] == 'E')
				move_exit_up(game, x, y);
			if (x == game->x_exit && y == game->y_exit)
				handle_exit_up(game, x, y);
			else
			{
				if (game->map[y - 1][x] == 'C')
					game->count_collectibles--;
				mlx_put_image_to_window(game->mlx, game->window,
					game->player_img, x * XPM_WIDTH, (y - 1) * XPM_HEIGHT);
				mlx_put_image_to_window(game->mlx, game->window,
					game->space_img, x * XPM_WIDTH, y * XPM_HEIGHT);
				game->map[y][x] = '0';
				game->map[y - 1][x] = 'P';
			}
			game->y--;
			ft_printf("Moves = %d\n", ++(game->move));
		}
	}
}

void	move_player_down(t_game *game)
{
	int (x), y = game->y;
	x = game->x;
	if (game->map[y + 1][x])
	{
		if (game->map[y + 1][x] != '1')
		{
			if (game->map[y + 1][x] == 'E')
				move_exit_down(game, x, y);
			if (x == game->x_exit && y == game->y_exit)
				handle_exit_down(game, x, y);
			else
			{
				if (game->map[y + 1][x] == 'C')
					game->count_collectibles--;
				mlx_put_image_to_window(game->mlx, game->window,
					game->player_img, x * XPM_WIDTH, (y + 1) * XPM_HEIGHT);
				mlx_put_image_to_window(game->mlx, game->window,
					game->space_img, x * XPM_WIDTH, y * XPM_HEIGHT);
				game->map[y][x] = '0';
				game->map[y + 1][x] = 'P';
			}
			game->y++;
			ft_printf("Moves = %d\n", ++(game->move));
		}
	}
}

void	move_player_right(t_game *game)
{
	int (x), y = game->y;
	x = game->x;
	if (game->map[y][x + 1])
	{
		if (game->map[y][x + 1] != '1')
		{
			if (game->map[y][x + 1] == 'E')
				move_exit_right(game, x, y);
			if (x == game->x_exit && y == game->y_exit)
				handle_exit_right(game, x, y);
			else
			{
				if (game->map[y][x + 1] == 'C')
					game->count_collectibles--;
				mlx_put_image_to_window(game->mlx, game->window,
					game->player_img, (x + 1) * XPM_WIDTH, y * XPM_HEIGHT);
				mlx_put_image_to_window(game->mlx, game->window,
					game->space_img, x * XPM_WIDTH, y * XPM_HEIGHT);
				game->map[y][x] = '0';
				game->map[y][x + 1] = 'P';
			}
			game->x++;
			ft_printf("Moves = %d\n", ++(game->move));
		}
	}
}

void	move_player_left(t_game *game)
{
	int (x), y = game->y;
	x = game->x;
	if (x > 0)
	{
		if (game->map[y][x - 1] != '1')
		{
			if (game->map[y][x - 1] == 'E')
				move_exit_left(game, x, y);
			if (x == game->x_exit && y == game->y_exit)
				handle_exit_left(game, x, y);
			else
			{
				if (game->map[y][x - 1] == 'C')
					game->count_collectibles--;
				mlx_put_image_to_window(game->mlx, game->window,
					game->player_img, (x - 1) * XPM_WIDTH, y * XPM_HEIGHT);
				mlx_put_image_to_window(game->mlx, game->window,
					game->space_img, x * XPM_WIDTH, y * XPM_HEIGHT);
				game->map[y][x] = '0';
				game->map[y][x - 1] = 'P';
			}
			game->x--;
			ft_printf("Moves = %d\n", ++(game->move));
		}
	}
}
