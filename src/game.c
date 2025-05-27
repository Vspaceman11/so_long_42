/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:26:21 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/27 18:12:32 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_game_init(t_game *game)
// {

// 	t_textures textures;
// 	u_int32_t idx;

// 	game->map = ft_read_map("maps/map1.ber");
// 	if (!game->map || ft_validate_map(game->map))
// 		exit(EXIT_FAILURE);
// 	ft_map_size(game);
// 	game->mlx = mlx_init(game->map_row * 64, game->map_col * 64, "so_long", true);
// 	if (!game)
// 		exit(EXIT_FAILURE);
// 	// textures.floor_tx_c = mlx_load_png("textures/Cute_Fantasy/Grass_Middle.png");
// 	textures.wall_texture = mlx_load_png("textures/png/Water_Middle.png");
// 	textures.player_texture = mlx_load_png("textures/png/player_witing/player000.png");

// 	// game->images.floor_img = mlx_texture_to_image(game->mlx, textures.floor_tx_c);
// 	game->images.wall_img = mlx_texture_to_image(game->mlx, textures.wall_texture);
// 	game->images.player_img = mlx_texture_to_image(game->mlx, textures.player_texture);
// 	game->map_row = 0;
// 	game->map_col = 0;
// 	init_textures(game);
// 	while (game->map[game->map_row])
// 	{
// 		game->map_col = 0;
// 		while (game->map[game->map_row][game->map_col])
// 		{
// 			if (game->map[game->map_row][game->map_col] == '0')
// 			{
// 				int mask = get_tile_mask(game, game->map_row, game->map_col);
// 				mlx_texture_t *tx = get_ground_texture(game, mask);
// 				game->images.floor_img = mlx_texture_to_image(game->mlx, tx);
// 				idx = mlx_image_to_window(game->mlx, game->images.floor_img, game->map_col * 64, game->map_row * 64);
// 				mlx_resize_image(game->images.floor_img, 64, 64);
// 				game->images.floor_img->instances[idx].z = 2;
// 			}
// 			if (game->map[game->map_row][game->map_col] == '1')
// 			{

// 				idx = mlx_image_to_window(game->mlx, game->images.wall_img, game->map_col * 64, game->map_row * 64);
// 				mlx_resize_image(game->images.wall_img, 64, 64);

// 				game->images.wall_img->instances[idx].z = 0;
// 			}
// 			if (game->map[game->map_row][game->map_col] == 'P')
// 			{
// 				idx = mlx_image_to_window(game->mlx, game->images.player_img, game->map_col * 64, game->map_row * 64);
// 				mlx_resize_image(game->images.player_img, 64, 64);

// 				game->images.player_img->instances[idx].z = 3;
// 			}
// 			game->map_col++;
// 		}
// 		game->map_row++;
// 	}


// 	mlx_loop(game->mlx);
// 	mlx_terminate(game->mlx);
// 	exit(EXIT_SUCCESS);
// }

void	ft_game_init(t_game *game)
{
	u_int32_t	idx;

	game->map = ft_read_map("maps/map1.ber");
	if (!game->map || ft_validate_map(game->map))
		exit(EXIT_FAILURE);
	ft_map_size(game);

	game->mlx = mlx_init(game->map_col * 64, game->map_row * 64, "so_long", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);

	init_textures(game);

	game->textures.wall_texture = mlx_load_png("textures/png/Water_Middle.png");
	game->textures.player_texture = mlx_load_png("textures/png/player_witing/player000.png");

	if (!game->textures.wall_texture || !game->textures.player_texture)
	{
		fprintf(stderr, "Error: Failed to load one or more textures.\n");
		exit(EXIT_FAILURE);
	}

	mlx_image_t *wall_img = mlx_texture_to_image(game->mlx, game->textures.wall_texture);
	mlx_image_t *player_img = mlx_texture_to_image(game->mlx, game->textures.player_texture);
	if (!wall_img || !player_img)
	{
		fprintf(stderr, "Error: Failed to convert texture to image.\n");
		exit(EXIT_FAILURE);
	}

	game->images.wall_img = wall_img;
	game->images.player_img = player_img;
	game->map_row = 0;
	game->map_col = 0;
	while (game->map[game->map_row])
	{
		game->map_col = 0;
		while (game->map[game->map_row][game->map_col])
		{
			char tile = game->map[game->map_row][game->map_col];
			if (tile == '0')
			{
				int mask = get_tile_mask(game, game->map_row, game->map_col);
				mlx_texture_t *tx = get_ground_texture(game, mask);
				if (!tx)
					continue;

				game->images.floor_img = mlx_texture_to_image(game->mlx, tx);
				if (!game->images.floor_img)
					continue;
				mlx_resize_image(game->images.floor_img, 64, 64);
				idx = mlx_image_to_window(game->mlx, game->images.floor_img, game->map_col * 64, game->map_row * 64);
				game->images.floor_img->instances[idx].z = 1;
			}
			else if (tile == '1')
			{
				idx = mlx_image_to_window(game->mlx, wall_img, game->map_col * 64, game->map_row * 64);
				mlx_resize_image(game->images.wall_img, 64, 64);
				wall_img->instances[idx].z = 0;
			}
			else if (tile == 'P')
			{
				idx = mlx_image_to_window(game->mlx, player_img, game->map_col * 64, game->map_row * 64);
				mlx_resize_image(game->images.player_img, 64, 64);
				player_img->instances[idx].z = 2;
			}
			game->map_col++;
		}
		game->map_row++;
	}

	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
