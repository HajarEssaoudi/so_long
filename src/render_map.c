/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:58:53 by hes-saou          #+#    #+#             */
/*   Updated: 2025/03/15 01:43:46 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_xpm(t_game *game)
{
	int		img_width;
	int		img_height;
	game->mlx = mlx_init();
	if (!game->mlx)
		(free_map(game), free(game), ft_putstr_fd("Error:\n mlx_init failed", 2));
	game->window = mlx_new_window(game->mlx,(game->map_width) * XPM_WIDTH, (game->map_height) * XPM_HEIGHT , "so_long");
	if(!game->window)
		(free_map(game), free(game), ft_putstr_fd("Error: mlx_new_window failed", 2));
	game->player_img = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", &img_width, &img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, "./textures/collectible.xpm", &img_width,&img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &img_width,&img_height);
	game->space_img = mlx_xpm_file_to_image(game->mlx, "./textures/space.xpm", &img_width,&img_height);
	game->wall_img= mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &img_width,&img_height);
	if(!game->wall_img || !game->space_img || !game->collectible_img || !game->exit_img || !game->player_img)
		(free_map(game), free(game), ft_putstr_fd("Error:\n mlx_xpm_file_to_image", 2));
}

void	render_map(t_game *game)
{
	int	(x), y;
	x = game->y;
	y = game->x;
	while(game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] =='1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall_img, x * XPM_WIDTH, y * XPM_HEIGHT);
			else if (game->map[y][x] =='0')
				mlx_put_image_to_window(game->mlx, game->window, game->space_img, x * XPM_WIDTH, y * XPM_HEIGHT);
			if (game->map[y][x] =='P')
				mlx_put_image_to_window(game->mlx, game->window, game->player_img, x * XPM_WIDTH, y * XPM_HEIGHT);
			else if (game->map[y][x] =='E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit_img, x * XPM_WIDTH, y * XPM_HEIGHT);
			else if (game->map[y][x] =='C')
				mlx_put_image_to_window(game->mlx, game->window, game->collectible_img, x * XPM_WIDTH, y * XPM_HEIGHT);
			x++;
		}
		y++;
	}
}

