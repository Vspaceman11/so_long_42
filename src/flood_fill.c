/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:36:43 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/13 16:21:43 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Creates a deep copy of the 2D map array.
 *
 * Allocates memory for a new map array and duplicates each
 * string from the original map. Returns NULL on failure.
 *
 * @param map The original 2D map array to copy.
 * @return A pointer to the new copied map, or NULL on error.
 */
char	**ft_copy_map(char **map)
{
	char	**map_cpy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	map_cpy = malloc(sizeof(char *) * (i + 1));
	if (!map_cpy)
		return (NULL);
	map_cpy[i] = NULL;
	i = 0;
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
		{
			while (--i >= 0)
				free(map_cpy[i]);
			free(map_cpy);
			return (NULL);
		}
		i++;
	}
	return (map_cpy);
}

/**
 * @brief Frees memory allocated for the 2D map array.
 *
 * Iterates through each row of the map, frees the row string,
 * then frees the map pointer itself.
 *
 * @param map The 2D array of strings representing the map.
 */
void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/**
 * @brief Recursively marks reachable areas on the map using flood fill.
 *
 * Starts from position (row, col) and marks all connected cells
 * that are not walls ('1') or already visited ('F') as visited by
 * replacing them with 'F'. This is used to check map path validity.
 *
 * @param map The 2D map array to modify.
 * @param row Current row index.
 * @param col Current column index.
 */
void	ft_flood_fill(char **map, int row, int col)
{
	if (map[row][col] == '1' || map[row][col] == 'F')
		return ;
	map[row][col] = 'F';
	ft_flood_fill(map, row + 1, col);
	ft_flood_fill(map, row - 1, col);
	ft_flood_fill(map, row, col + 1);
	ft_flood_fill(map, row, col - 1);
}
