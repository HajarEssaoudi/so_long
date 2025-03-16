/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:35:47 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/16 13:06:35 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_game *game)
{
	int(i), j = 0;
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

void	move_player_up(t_game *game)
{
	int(x), y;
	player_position(game);
	x = game->x;
	y = game->y;
	if (y > 0)
	{
		if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
		{
			if (game->map[y - 1][x] == 'C')
				game->count_collectibles--;
			mlx_put_image_to_window(game->mlx, game->window, game->player_img, x
				* XPM_WIDTH, (y - 1) * XPM_HEIGHT);
			mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
				* XPM_WIDTH, (y)*XPM_HEIGHT);
			game->move++;
			ft_printf("Move: %d\n", game->move);
			game->map[y][x] = '0';
			game->map[y - 1][x] = 'P';
			y--;
		}
		else if (game->map[y - 1][x] == 'E' && game->count_collectibles == 0)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->player_img, x
				* XPM_WIDTH, (y - 1) * XPM_HEIGHT);
			mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
				* XPM_WIDTH, (y)*XPM_HEIGHT);
			close_window(game);
		}
	}
	game->x = x;
	game->y = y;
}

void	move_player_down(t_game *game)
{
	int(x), y;
	player_position(game);
	x = game->x;
	y = game->y;
	if (game->map[y + 1][x])
	{
		if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
		{
			if (game->map[y + 1][x] == 'C')
				game->count_collectibles--;
			mlx_put_image_to_window(game->mlx, game->window, game->player_img, x
				* XPM_WIDTH, (y + 1) * XPM_HEIGHT);
			mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
				* XPM_WIDTH, (y)*XPM_HEIGHT);
			game->move++;
			ft_printf("Move: %d\n", game->move);
			game->map[y][x] = '0';
			game->map[y + 1][x] = 'P';
			y++;
		}
		else if (game->map[y + 1][x] == 'E' && game->count_collectibles == 0)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->player_img, x
				* XPM_WIDTH, (y + 1) * XPM_HEIGHT);
			mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
				* XPM_WIDTH, (y)*XPM_HEIGHT);
			close_window(game);
		}
	}
	game->x = x;
	game->y = y;
}

void	move_player_left(t_game *game)
{
	int(x), y;
	player_position(game);
	x = game->x;
	y = game->y;
	if (x > 0)
	{
		if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
		{
			if (game->map[y][x - 1] == 'C')
				game->count_collectibles--;
			mlx_put_image_to_window(game->mlx, game->window, game->player_img,
				(x - 1) * XPM_WIDTH, y * XPM_HEIGHT);
			mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
				* XPM_WIDTH, (y)*XPM_HEIGHT);
			game->move++;
			ft_printf("Move: %d\n", game->move);
			game->map[y][x] = '0';
			game->map[y][x - 1] = 'P';
			x--;
		}
		else if (game->map[y][x - 1] == 'E' && game->count_collectibles == 0)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->player_img,
				(x - 1) * XPM_WIDTH, y * XPM_HEIGHT);
			mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
				* XPM_WIDTH, (y)*XPM_HEIGHT);
			close_window(game);
		}
	}
	game->x = x;
	game->y = y;
}

void	move_player_right(t_game *game)
{
	int(x), y;
	player_position(game);
	x = game->x;
	y = game->y;
	if (game->map[y][x + 1])
	{
		if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
		{
			if (game->map[y][x + 1] == 'C')
				game->count_collectibles--;
			mlx_put_image_to_window(game->mlx, game->window, game->player_img,
				(x + 1) * XPM_WIDTH, y * XPM_HEIGHT);
			mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
				* XPM_WIDTH, (y)*XPM_HEIGHT);
			game->move++;
			ft_printf("Move: %d\n", game->move);
			game->map[y][x] = '0';
			game->map[y][x + 1] = 'P';
			x++;
		}
		else if (game->map[y][x + 1] == 'E' && game->count_collectibles == 0)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->player_img,
				(x + 1) * XPM_WIDTH, y * XPM_HEIGHT);
			mlx_put_image_to_window(game->mlx, game->window, game->space_img, x
				* XPM_WIDTH, (y)*XPM_HEIGHT);
			close_window(game);
		}
	}
	game->x = x;
	game->y = y;
}
