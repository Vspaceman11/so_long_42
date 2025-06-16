/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:59:26 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/16 15:10:46 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Handle collectible pickup at given map coordinates.
 *
 * Updates the map cell to '0' (empty), decreases collectibles count,
 * and disables the corresponding collectible image instance to hide it.
 *
 * @param game Pointer to the game state structure.
 * @param x X-coordinate on the map.
 * @param y Y-coordinate on the map.
 */
static void	ft_handle_collectible(t_game *game, int x, int y)
{
	size_t			i;
	mlx_instance_t	*inst;

	game->map[y][x] = '0';
	game->col_remaining--;
	i = 0;
	while (i < game->images.coll_img->count)
	{
		inst = &game->images.coll_img->instances[i];
		if (inst->x == x * 64 && inst->y == y * 64)
		{
			inst->enabled = false;
			break ;
		}
		i++;
	}
}

/**
 * @brief Handles a single key press event to control player movement or exit.
 *
 * This function is called on key events. It only reacts to actual key presses
 * (ignores key hold and release events). Based on the key pressed, it moves
 * the player character in one of the four cardinal directions or exits the game.
 *
 * Supported keys:
 * - W / Up Arrow: Move up
 * - S / Down Arrow: Move down
 * - A / Left Arrow: Move left
 * - D / Right Arrow: Move right
 * - Escape: Exit the game
 *
 * @param keydata Contains the key pressed and its action type.
 * @param param Pointer to the game structure, passed from the event hook.
 */
void	ft_handle_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		ft_player_move(game, 0, -1);
	if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		ft_player_move(game, 0, 1);
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		ft_player_move(game, -1, 0);
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		ft_player_move(game, 1, 0);
}

/**
 * @brief Check if the player reached the exit with all collectibles collected.
 *
 * If no collectibles remain, print a victory message, close the window,
 * and return 1 to indicate game end. Otherwise, return 0.
 *
 * @param game Pointer to the game structure.
 * @return int 1 if exit condition met, 0 otherwise.
 */
static int	ft_check_exit_reached(t_game *game)
{
	if (game->col_remaining == 0)
	{
		ft_printf("You win in %d moves!\n", game->player_moves + 1);
		mlx_close_window(game->mlx);
		return (1);
	}
	return (0);
}

/**
 * @brief Move the player by given offsets if the move is valid.
 *
 * Checks if the new position is inside map boundaries and not a wall.
 * Handles collectible pick-up and exit conditions.
 * Updates player position, image coordinates, and move count.
 *
 * @param game Pointer to the game structure.
 * @param dx   Offset in the x-direction (columns).
 * @param dy   Offset in the y-direction (rows).
 */
void	ft_player_move(t_game *game, int dx, int dy)
{
	int		n_x;
	int		n_y;
	char	tile;

	n_x = game->player_x + dx;
	n_y = game->player_y + dy;
	if (n_x < 0 || n_y < 0 || n_y >= game->map_row || n_x >= game->map_col)
		return ;
	tile = game->map[n_y][n_x];
	if (tile == '1')
		return ;
	if (tile == 'C')
		ft_handle_collectible(game, n_x, n_y);
	if (tile == 'E' && ft_check_exit_reached(game))
		return ;
	game->player_x = n_x;
	game->player_y = n_y;
	game->images.player_img->instances[game->player_inst_idx].x = n_x * 64;
	game->images.player_img->instances[game->player_inst_idx].y = n_y * 64;
	game->player_moves++;
	ft_printf("Moves: %d\n", game->player_moves);
}
