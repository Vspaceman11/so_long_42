/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:59:26 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/10 15:11:34 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_input(void *param)
{
	t_game *game;

	game = (t_game *)param;
	game->frame_count++;
	if (game->frame_count < game->input_cooldown)
		return ;
	game->frame_count = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) || mlx_is_key_down(game->mlx, MLX_KEY_UP))
		ft_player_move(game, 0, -1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S) || mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		ft_player_move(game, 0, 1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A) || mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		ft_player_move(game, -1, 0);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D) || mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		ft_player_move(game, 1, 0);
}

void	ft_player_move(t_game *game, int dx, int dy)
{
	int				new_x;
	int				new_y;
	char			tile;
	mlx_instance_t	*inst;
	size_t			i;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_y < 0 || new_y >= game->map_col || new_x >= game->map_row)
		return;
	i = 0;
	tile = game->map[new_y][new_x];
	if (tile == '1')
		return ;
	if (tile == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->col_remaining--;
		while (i < game->images.collectible_img->count)
		{
			inst = &game->images.collectible_img->instances[i];
			if (inst->x == new_x * 64 && inst->y == new_y * 64)
			{
				inst->enabled = false;
				break;
			}
			i++;
		}
	}
	if (tile == 'E')
	{
		if (game->col_remaining == 0)
		{
			ft_printf("You win in %d moves!\n", game->player_moves + 1);
			mlx_close_window(game->mlx);
			return ;
		}
		else
			return ;
	}
	game->player_x = new_x;
	game->player_y = new_y;
	game->images.player_img->instances[game->player_instance_idx].x = new_x * 64;
	game->images.player_img->instances[game->player_instance_idx].y = new_y * 64;
	game->player_moves++;
	ft_printf("Moves: %d\n", game->player_moves);
}
