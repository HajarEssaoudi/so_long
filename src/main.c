/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:32:09 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/14 03:48:24 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include <X11/keysym.h>

int	close_window(void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
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

int	what_key(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == XK_Escape)
	{
		close_window(game);
		exit(0);
	}
	return (0);
}


int	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->map_name = av[1];
	if (!check_map_name(ac, game->map_name))
		(free(game), exit(1));
	game->map_height = count_lines(game);
	game->map = store_map(game);
	if (check_map_validity(game))
	{
		game->map_width = ft_strlen_map(game->map[1]);
		render_map(game);
	}
	mlx_hook(game->window, 17, 1L>>0, close_window, game);
	mlx_hook(game->window, 2, 1L>>0, what_key, game);
	mlx_loop(game->mlx);
	return (0);
}
