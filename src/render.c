/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:24:49 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/13 16:42:03 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Place basic tile images on the window at given map coordinates.
 *
 * Places a floor tile on all coordinates. If tile is a wall ('1'),
 * places a wall tile on top. If tile is a collectible ('C'), places
 * collectible image on top of the floor tile.
 *
 * @param game Pointer to the game structure.
 * @param tile Character representing the tile type.
 * @param x X-coordinate (column) on the map.
 * @param y Y-coordinate (row) on the map.
 */
void	ft_place_basic_tiles(t_game *game, char tile, int x, int y)
{
	u_int32_t	idx;

	idx = mlx_image_to_window(game->mlx,
			game->images.floor_img, x * 64, y * 64);
	mlx_resize_image(game->images.floor_img, 64, 64);
	game->images.floor_img->instances[idx].z = 0;
	if (tile == '1')
	{
		idx = mlx_image_to_window(game->mlx,
				game->images.wall_img, x * 64, y * 64);
		mlx_resize_image(game->images.wall_img, 64, 64);
		game->images.wall_img->instances[idx].z = 1;
	}
	else if (tile == 'C')
	{
		idx = mlx_image_to_window(game->mlx,
				game->images.coll_img, x * 64, y * 64);
		mlx_resize_image(game->images.coll_img, 64, 64);
		game->images.coll_img->instances[idx].z = 2;
	}
}

/**
 * @brief Place special tile images for player and exit on the map.
 *
 * If tile is 'P', places player image, sets player position and instance.
 * If tile is 'E', places exit image on the map.
 *
 * @param game Pointer to the game structure.
 * @param tile Character representing the tile type ('P' or 'E').
 * @param x X-coordinate (column) on the map.
 * @param y Y-coordinate (row) on the map.
 */
void	ft_place_special_tiles(t_game *game, char tile, int x, int y)
{
	u_int32_t	idx;

	if (tile == 'P')
	{
		idx = mlx_image_to_window(game->mlx,
				game->images.player_img, x * 64, y * 64);
		mlx_resize_image(game->images.player_img, 64, 64);
		game->images.player_img->instances[idx].z = 4;
		game->player_inst_idx = idx;
		game->player_x = x;
		game->player_y = y;
	}
	else if (tile == 'E')
	{
		idx = mlx_image_to_window(game->mlx,
				game->images.exit_img, x * 64, y * 64);
		mlx_resize_image(game->images.exit_img, 64, 64);
		game->images.exit_img->instances[idx].z = 3;
	}
}

/**
 * @brief Place a tile on the map by delegating to helper functions.
 *
 * Calls functions to place basic tiles (floor, wall, collectibles) and
 * special tiles (player, exit) at given map coordinates.
 *
 * @param game Pointer to the game structure.
 * @param tile Character representing the tile type.
 * @param x X-coordinate (column) on the map.
 * @param y Y-coordinate (row) on the map.
 */
void	ft_place_tile(t_game *game, char tile, int x, int y)
{
	ft_place_basic_tiles(game, tile, x, y);
	ft_place_special_tiles(game, tile, x, y);
}

/**
 * @brief Render the entire game map by placing each tile on the window.
 *
 * Iterates through each row and column of the map array and places
 * the corresponding tile image at the correct position.
 *
 * @param game Pointer to the game structure containing the map.
 */
void	ft_map_render(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			ft_place_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
