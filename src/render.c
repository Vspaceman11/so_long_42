/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:24:49 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/27 17:26:54 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		printf("%s", game->map[i]);
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
void	init_textures(t_game *game)
{
	game->textures.floor_tx_tl = mlx_load_png("textures/png/floor/floor_tl.png");
	game->textures.floor_tx_tr = mlx_load_png("textures/png/floor/floor_tr.png");
	game->textures.floor_tx_bl = mlx_load_png("textures/png/floor/floor_bl.png");
	game->textures.floor_tx_br = mlx_load_png("textures/png/floor/floor_br.png");
	game->textures.floor_tx_top = mlx_load_png("textures/png/floor/floor_t.png");
	game->textures.floor_tx_b = mlx_load_png("textures/png/floor/floor_b.png");
	game->textures.floor_tx_l = mlx_load_png("textures/png/floor/floor_l.png");
	game->textures.floor_tx_r = mlx_load_png("textures/png/floor/floor_r.png");
	game->textures.floor_tx_c = mlx_load_png("textures/png/floor/floor_c.png");

}

int	get_tile_mask(t_game *game, int row, int col)
{
	int	mask;

	mask = 0;
	if (row > 0 && game->map[row - 1][col] == '1')
		mask |= TOP;
	if (game->map[row][col + 1] && game->map[row][col + 1] == '1')
		mask |= RIGHT;
	if (game->map[row + 1] && game->map[row + 1][col] == '1')
		mask |= BOTTOM;
	if (col > 0 && game->map[row][col - 1] == '1')
		mask |= LEFT;
	return (mask);
}

mlx_texture_t	*get_ground_texture(t_game *game, int mask)
{
	if (mask == (TOP | LEFT))
		return (game->textures.floor_tx_tl);
	else if (mask == (TOP | RIGHT))
		return (game->textures.floor_tx_tr);
	else if (mask == (BOTTOM | LEFT))
		return (game->textures.floor_tx_bl);
	else if (mask == (BOTTOM | RIGHT))
		return (game->textures.floor_tx_br);
	else if (mask == TOP)
		return (game->textures.floor_tx_top);
	else if (mask == BOTTOM)
		return (game->textures.floor_tx_b);
	else if (mask == LEFT)
		return (game->textures.floor_tx_l);
	else if (mask == RIGHT)
		return (game->textures.floor_tx_r);
	else
		return (game->textures.floor_tx_c);
}

void	delete_tx(t_textures *tx)
{
	mlx_delete_texture(tx->floor_tx_tl);
	mlx_delete_texture(tx->floor_tx_tr);
	mlx_delete_texture(tx->floor_tx_bl);
	mlx_delete_texture(tx->floor_tx_br);
	mlx_delete_texture(tx->floor_tx_top);
	mlx_delete_texture(tx->floor_tx_b);
	mlx_delete_texture(tx->floor_tx_l);
	mlx_delete_texture(tx->floor_tx_r);
	mlx_delete_texture(tx->floor_tx_c);
}
