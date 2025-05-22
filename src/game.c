/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:26:21 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/22 17:35:25 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_game_init(void)
{
	mlx_t*	mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		return (perror("Error during MLX init ", 1));
}
