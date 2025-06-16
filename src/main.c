/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:52:55 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/16 14:29:22 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Main entry point of the so_long game.
 *
 * This function checks for the correct number of arguments, allocates memory
 * for the game structure, reads and validates the map, and initializes the
 * game if everything is correct.
 *
 * @param argc Argument count.
 * @param argv Argument vector, expects the map file as argv[1].
 * @return int Returns 0 on success, 1 on failure.
 */
int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
			return (perror("Map not in a .ber format"), 1);
		game = ft_calloc(1, sizeof(t_game));
		if (!game)
			return (perror("Memory allocation failed"), 1);
		game->map = ft_read_map(argv[1]);
		if (!game->map)
		{
			if (game->map)
				ft_free_map(game->map);
			free(game);
			return (perror("Failed to read map."), 1);
		}
		if (ft_validate_map(game->map))
			return (ft_free_map(game->map), free(game), 1);
		ft_game_init(game);
		return (0);
	}
	else
		return (perror("Usage: ./so_long <map_file.ber>"), 1);
}
