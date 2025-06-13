/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:50:01 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/13 16:43:48 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Free all loaded images and textures in the game.
 *
 * Checks if the game pointer is valid, then deletes each image and texture
 * if it exists, freeing allocated graphics resources.
 *
 * @param game Pointer to the game structure containing images and textures.
 */
void	ft_free_images(t_game *game)
{
	if (!game)
		return ;
	if (game->images.wall_img)
		mlx_delete_image(game->mlx, game->images.wall_img);
	if (game->images.floor_img)
		mlx_delete_image(game->mlx, game->images.floor_img);
	if (game->images.coll_img)
		mlx_delete_image(game->mlx, game->images.coll_img);
	if (game->images.player_img)
		mlx_delete_image(game->mlx, game->images.player_img);
	if (game->images.exit_img)
		mlx_delete_image(game->mlx, game->images.exit_img);
	if (game->textures.wall_tx)
		mlx_delete_texture(game->textures.wall_tx);
	if (game->textures.floor_tx)
		mlx_delete_texture(game->textures.floor_tx);
	if (game->textures.coll_tx)
		mlx_delete_texture(game->textures.coll_tx);
	if (game->textures.player_tx)
		mlx_delete_texture(game->textures.player_tx);
	if (game->textures.exit_tx)
		mlx_delete_texture(game->textures.exit_tx);
}

/**
 * @brief Clean up all game resources and exit the program.
 *
 * Frees images, map, terminates the mlx instance, and frees the game
 * structure itself. Then exits the program with success status.
 *
 * @param game Pointer to the game structure to clean up.
 */
void	ft_exit_game(t_game *game)
{
	ft_free_images(game);
	ft_free_map(game->map);
	mlx_terminate(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}

/**
 * @brief Callback function for window close event.
 *
 * This function is called when the window close button is pressed.
 * It triggers a proper game cleanup and exits the program.
 *
 * @param param Pointer to the game structure (t_game *).
 */
void	ft_hook_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_exit_game(game);
}
