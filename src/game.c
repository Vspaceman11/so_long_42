/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:26:21 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/23 17:59:46 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(t_game *game)
{
	t_textures textures;
	game->map = ft_read_map("maps/map1.ber");
	if (!game->map || ft_validate_map(game->map))
		exit(EXIT_FAILURE);
	ft_map_size(game);
	game->mlx = mlx_init(game->map_row * 128, game->map_col * 128, "so_long", true);
	if (!game)
		exit(EXIT_FAILURE);

	textures.player_texture = mlx_load_png("textures/Soldier/ezgif-split/soldier_boy000.png");
	textures.floor_texture = mlx_load_png("textures/Textures-16.png");

	game->images.floor_img = mlx_texture_to_image(game->mlx, textures.floor_texture);
	game->images.player_img = mlx_texture_to_image(game->mlx, textures.player_texture);
	// mlx_resize_image(game->images.player_img, 128, 128);
	game->map_row = 0;
	game->map_col = 0;
	while (game->map[game->map_row])
	{
		game->map_col = 0;
		while (game->map[game->map_row][game->map_col])
		{
			if (game->map[game->map_row][game->map_col] == '1')
			{
				mlx_resize_image(game->images.player_img, 200, 200);
				mlx_image_to_window(game->mlx, game->images.player_img, game->map_col * 128, game->map_row * 128);

			}
			game->map_col++;
		}
		game->map_row++;
	}

	mlx_resize_image(game->images.floor_img, 64, 64);

	// mlx_image_to_window(game->mlx, game->images.floor_img, 1, 1);
	//mlx_image_to_window(game->mlx, game->images.player_img, 1, 1);


	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
