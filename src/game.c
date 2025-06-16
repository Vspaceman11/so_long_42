/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:26:21 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/16 15:11:09 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initialize game map and window parameters.
 *
 * Calculates map size, initializes MLX window with the correct size,
 * and sets initial game variables.
 *
 * @param game Pointer to the game structure.
 */
void	ft_game_map_init(t_game *game)
{
	ft_map_size(game);
	game->mlx = mlx_init(game->map_col * TILE_SIZE,
			game->map_row * TILE_SIZE, "so_long", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->col_remaining = ft_count_collectibles(game->map);
}

/**
 * @brief Load all required textures for the game from PNG files.
 *
 * This function loads texture images from disk and stores them in the
 * game's texture fields. If any texture fails to load, it prints an
 * error message and terminates the program.
 *
 * @param game Pointer to the game state structure.
 */
void	ft_textures_load(t_game *game)
{
	game->textures.floor_tx = mlx_load_png("textures/floor/floor.png");
	game->textures.wall_tx = mlx_load_png("textures/wall/wall.png");
	game->textures.player_tx = mlx_load_png("textures/player/player.png");
	game->textures.coll_tx = mlx_load_png("textures/col/col.png");
	game->textures.exit_tx = mlx_load_png("textures/exit/exit_o.png");
	if (!game->textures.floor_tx || !game->textures.wall_tx
		|| !game->textures.player_tx || !game->textures.coll_tx
		|| !game->textures.exit_tx)
	{
		ft_printf("Error: Failed to load one or more textures.\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief Convert loaded textures into MLX images.
 *
 * This function creates images from the textures stored in the game
 * structure by converting each texture using mlx_texture_to_image.
 * It stores the resulting images back into the game's image fields.
 *
 * If any image creation fails, the function prints an error message
 * and exits the program immediately.
 *
 * @param game Pointer to the game state structure.
 */
void	ft_images_create(t_game *game)
{
	game->images.floor_img = mlx_texture_to_image(game->mlx,
			game->textures.floor_tx);
	game->images.wall_img = mlx_texture_to_image(game->mlx,
			game->textures.wall_tx);
	game->images.player_img = mlx_texture_to_image(game->mlx,
			game->textures.player_tx);
	game->images.coll_img = mlx_texture_to_image(game->mlx,
			game->textures.coll_tx);
	game->images.exit_img = mlx_texture_to_image(game->mlx,
			game->textures.exit_tx);
	if (!game->images.floor_img
		|| !game->images.wall_img || !game->images.player_img
		|| !game->images.coll_img || !game->images.exit_img)
	{
		ft_printf("Error: Failed to convert texture to image.\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief Initialize game components and start the game loop.
 *
 * This function initializes the game map, loads textures, creates images,
 * renders the map, sets up event hooks for window closing and input handling,
 * and finally starts the MLX event loop.
 *
 * @param game Pointer to the game state structure.
 */
void	ft_game_init(t_game *game)
{
	ft_game_map_init(game);
	ft_textures_load(game);
	ft_images_create(game);
	ft_map_render(game);
	mlx_close_hook(game->mlx, ft_hook_close, game);
	mlx_key_hook(game->mlx, ft_handle_input, game);
	mlx_loop(game->mlx);
}
