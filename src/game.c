/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:26:21 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/10 15:22:16 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(t_game *game)
{
	u_int32_t	idx;

	game->map = ft_read_map("maps/test.ber");
	if (!game->map || ft_validate_map(game->map))
		exit(EXIT_FAILURE);
	ft_map_size(game);

	game->mlx = mlx_init(game->map_col * 256, game->map_row * 64, "so_long", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->frame_count = 0;
	game->input_cooldown = 10;
	game->col_remaining = ft_count_collectibles(game->map);

	game->textures.floor_texture = mlx_load_png("textures/png/floor/floor.png");
	game->textures.wall_texture = mlx_load_png("textures/png/wall/wall.png");
	game->textures.player_texture = mlx_load_png("textures/png/player/player013.png");
	game->textures.collectible_texture = mlx_load_png("textures/png/col/col.png");
	game->textures.exit_texture = mlx_load_png("textures/png/exit/exit_c.png");
	if (!game->textures.floor_texture || !game->textures.wall_texture || !game->textures.player_texture
		 || !game->textures.collectible_texture || !game->textures.exit_texture)
	{
		fprintf(stderr, "Error: Failed to load one or more textures.\n");
		exit(EXIT_FAILURE);
	}

	mlx_image_t *floor_img = mlx_texture_to_image(game->mlx, game->textures.floor_texture);
	mlx_image_t *wall_img = mlx_texture_to_image(game->mlx, game->textures.wall_texture);
	mlx_image_t *player_img = mlx_texture_to_image(game->mlx, game->textures.player_texture);
	mlx_image_t *collectible_img = mlx_texture_to_image(game->mlx, game->textures.collectible_texture);
	mlx_image_t *exit_img = mlx_texture_to_image(game->mlx, game->textures.exit_texture);
	if (!floor_img || !wall_img || !player_img || !collectible_img || !exit_img)
	{
		fprintf(stderr, "Error: Failed to convert texture to image.\n");
		exit(EXIT_FAILURE);
	}

	game->images.floor_img = floor_img;
	game->images.wall_img = wall_img;
	game->images.player_img = player_img;
	game->images.collectible_img = collectible_img;
	game->images.exit_img = exit_img;
	// game->map_row = 0;
	// game->map_col = 0;
	int y = 0;
	while (game->map[y])
	{
		// game->map_col = 0;
		int x = 0;
		while (game->map[y][x])
		{
			char tile = game->map[y][x];
				idx = mlx_image_to_window(game->mlx, game->images.floor_img, x * 64, y * 64);
				mlx_resize_image(game->images.floor_img, 64, 64);
				game->images.floor_img->instances[idx].z = 0;
			if (tile == '1')
			{
				idx = mlx_image_to_window(game->mlx, wall_img, x * 64, y * 64);
				mlx_resize_image(game->images.wall_img, 64, 64);
				wall_img->instances[idx].z = 1;
			}
			else if (tile == 'C')
			{
				idx = mlx_image_to_window(game->mlx, collectible_img, x * 64, y * 64);
				mlx_resize_image(game->images.collectible_img, 64, 64);
				collectible_img->instances[idx].z = 2;
			}
			else if (tile == 'P')
			{
				idx = mlx_image_to_window(game->mlx, player_img, x * 64, y * 64);
				mlx_resize_image(game->images.player_img, 64, 64);
				player_img->instances[idx].z = 4;
				game->player_instance_idx = idx;
				game->player_x = x;
				game->player_y = y;
			}
			else if (tile == 'E')
			{
				idx = mlx_image_to_window(game->mlx, exit_img, x * 64, y * 64);
				mlx_resize_image(game->images.exit_img, 64, 64);
				player_img->instances[idx].z = 3;
			}
			x++;
		}
		y++;
	}
	mlx_loop_hook(game->mlx, ft_handle_input, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
