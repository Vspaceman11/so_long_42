/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:59:26 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/13 16:39:28 by vpushkar         ###   ########.fr       */
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
 * @brief Handle player input with frame-based cooldown.
 *
 * Increments frame counter and processes input only when cooldown expires.
 * Supports movement keys (W/A/S/D or arrow keys) and Escape key to close.
 * Calls ft_player_move with direction offsets based on input.
 *
 * @param param Pointer to the game structure.
 */
void	ft_handle_input(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->frame_count++;
	if (game->frame_count < game->input_cooldown)
		return ;
	game->frame_count = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		|| mlx_is_key_down(game->mlx, MLX_KEY_UP))
		ft_player_move(game, 0, -1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		ft_player_move(game, 0, 1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		|| mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		ft_player_move(game, -1, 0);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		|| mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
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
