/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:26:21 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/11 17:46:00 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	 ft_game_map_init(t_game *game)
{
	game->map = ft_read_map("maps/test2.ber");
	if (!game->map || ft_validate_map(game->map))
		exit(EXIT_FAILURE);
	ft_map_size(game);
	game->mlx = mlx_init(game->map_col * 256, game->map_row * 64, "so_long", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->frame_count = 0;
	game->input_cooldown = 10;
	game->col_remaining = ft_count_collectibles(game->map);
}
void	ft_textures_load(t_game *game)
{
	game->textures.floor_tx = mlx_load_png("textures/png/floor/floor.png");
	game->textures.wall_tx = mlx_load_png("textures/png/wall/wall.png");
	game->textures.player_tx = mlx_load_png("textures/png/player/player.png");
	game->textures.coll_tx = mlx_load_png("textures/png/col/col.png");
	game->textures.exit_tx = mlx_load_png("textures/png/exit/exit_o.png");
	if (!game->textures.floor_tx || !game->textures.wall_tx
		|| !game->textures.player_tx || !game->textures.coll_tx
		|| !game->textures.exit_tx)
	{
		ft_printf("Error: Failed to load one or more textures.\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_images_create(t_game *game)
{
	game->images.floor_img = mlx_texture_to_image(game->mlx, game->textures.floor_tx);
	game->images.wall_img = mlx_texture_to_image(game->mlx, game->textures.wall_tx);
	game->images.player_img = mlx_texture_to_image(game->mlx, game->textures.player_tx);
	game->images.coll_img = mlx_texture_to_image(game->mlx, game->textures.coll_tx);
	game->images.exit_img = mlx_texture_to_image(game->mlx, game->textures.exit_tx);
	if (!game->images.floor_img || !game->images.wall_img || !game->images.player_img
		|| !game->images.coll_img || !game->images.exit_img)
	{
		ft_printf("Error: Failed to convert texture to image.\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_game_init(t_game *game)
{
	ft_game_map_init(game);
	ft_textures_load(game);
	ft_images_create(game);
	ft_map_render(game);

	mlx_loop_hook(game->mlx, ft_handle_input, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
