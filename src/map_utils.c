/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:56:07 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/13 16:19:19 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Checks if the map is a valid rectangle.
 *
 * This function verifies that all rows in the map have the same length as the
 * first row, ensuring the map is rectangular.
 *
 * @param map The 2D array of characters representing the map.
 * @return 1 if the map is rectangular, 0 otherwise.
 */
int	ft_is_valid_rectangular(char **map)
{
	size_t	width;
	int		row;

	row = 1;
	width = ft_strlen(map[0]);
	while (map[row])
	{
		if (ft_strlen(map[row]) != width)
			return (0);
		row++;
	}
	return (1);
}

/**
 * @brief Checks if the map is surrounded by walls ('1').
 *
 * This function verifies that the first and last rows, as well as the first
 * and last columns of the map, consist entirely of wall characters ('1').
 *
 * @param map The 2D array of characters representing the map.
 * @return 1 if the map is properly surrounded by walls, 0 otherwise.
 */
int	ft_is_surrended_by_walls(char **map)
{
	int	width;
	int	height;
	int	i;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Checks if the map contains only valid characters.
 *
 * Valid characters are: '0' (floor), '1' (wall), 'P' (player),
 * 'E' (exit), 'C' (collectible), and '\n' (newline).
 *
 * @param map The 2D array of characters representing the map.
 * @return 1 if all characters are valid, 0 otherwise.
 */
int	ft_has_valid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n'
				&& map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Checks if the map contains required elements.
 *
 * The map must contain exactly one player ('P'),
 * exactly one exit ('E'), and at least one collectible ('C').
 *
 * @param map The 2D array of characters representing the map.
 * @return 1 if the conditions are met, 0 otherwise.
 */
int	ft_has_required_elements(char **map)
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;
	int	c_count;

	i = 0;
	j = 0;
	p_count = 0;
	e_count = 0;
	c_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			p_count += (map[i][j] == 'P');
			e_count += (map[i][j] == 'E');
			c_count += (map[i][j] == 'C');
			j++;
		}
		i++;
	}
	return (p_count == 1 && e_count == 1 && c_count >= 1);
}

/**
 * @brief Counts the number of collectibles on the map.
 *
 * Iterates over the entire map and counts how many 'C'
 * characters (collectibles) are present.
 *
 * @param map The 2D array of characters representing the map.
 * @return The total count of collectibles found.
 */
int	ft_count_collectibles(char **map)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
