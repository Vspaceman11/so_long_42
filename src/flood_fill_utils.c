/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:30:23 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/13 16:28:52 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Finds the player's position on the map.
 *
 * Searches the 2D map array for the character 'P' which
 * represents the player. If found, stores the player's
 * row and column in the provided pointers.
 *
 * @param map The 2D map array.
 * @param x Pointer to an int to store the player's row.
 * @param y Pointer to an int to store the player's column.
 * @return 1 if player found, 0 otherwise.
 */
int	ft_find_player(char **map, int *x, int *y)
{
	int	row;
	int	col;

	row = 0;
	if (!map || !x || !y)
		return (0);
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'P')
			{
				*x = row;
				*y = col;
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

/**
 * @brief Check if unreachable collectibles or exit remain on the map.
 *
 * This function scans the map for any remaining collectibles ('C')
 * or exit ('E'). If any are found, it means they were not reached during
 * flood fill, indicating an invalid path.
 *
 * @param map The map after flood fill.
 * @return 1 if unreachable collectibles or exit remain, 0 otherwise.
 */
int	ft_check_remaining(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'C' || map[row][col] == 'E')
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}

/**
 * @brief Check if the player can reach all collectibles and exit.
 *
 * This function creates a copy of the map, finds the player's position,
 * performs a flood fill from that position, then checks if any collectibles
 * ('C') or exit ('E') remain unreachable.
 *
 * @param map The original game map.
 * @return 1 if the path to all required elements is valid, 0 otherwise.
 */
int	ft_is_path_valid(char **map)
{
	char	**map_cpy;
	int		row;
	int		col;

	map_cpy = ft_copy_map(map);
	if (!map_cpy)
		return (0);
	ft_find_player(map_cpy, &row, &col);
	ft_flood_fill(map_cpy, row, col);
	if (ft_check_remaining(map_cpy))
		return (ft_free_map(map_cpy), 0);
	ft_free_map(map_cpy);
	return (1);
}
