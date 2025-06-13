/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:52:55 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/13 15:05:56 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = ft_calloc(1, sizeof(t_game));
		if (!game)
			return (perror("Memory allocation failed"), 1);
		game->map = ft_read_map(argv[1]);
		if (!game->map)
			return (perror("Failed to read map."), free(game), 1);
		if (ft_validate_map(game->map))
			return (ft_free_map(game->map), free(game), 1);
		ft_game_init(game);
		return (0);
	}
	else
		return (perror("Usage: ./so_long <map_file.ber>"), 1);
}
